#include "gryphflix.h"
#include <stdio.h>
#include <string.h>

int numReviewers = NUMBER_REVIEWERS;
int numMovies = NUMBER_MOVIES;
int maxString = MAX_STR; 
int maxWords = MAX_WORDS;

//First Function

FILE *openFileForReading(char *fileName){

    FILE *newFile;
    newFile = fopen(fileName, "r");

    return newFile;
}

//Second Function

int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]){

    int numLines = 0;
    int x = 0;
    int returnValue; 

    //When new line happens we encounter newline char from fgetc, we increase line count
    while(!feof(file)){
        x = fgetc(file);
        if(x == '\n'){
            numLines = numLines +1;
        }
    }

    //if numLines equals number of movies then we save info from the file
    if(numLines == NUMBER_MOVIES){
        rewind(file);
        for(int i = 0; i < NUMBER_MOVIES; ++i){
            fgets(movieNames[i], MAX_STR, file);
        } 
        returnValue = 1;
    }else{
        printf("File not appropriate length\n");
        returnValue = 0;
    }
    fclose(file);
    return returnValue;
}

//Third Function

int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]){

    char tempString[MAX_STR];
    int numLines = 0;
    int x = 0;
    int returnValue; 

    //Checking for number of lines
    while(!feof(file)){
        x = fgetc(file);
        if(x == '\n'){
            numLines = numLines +1;
        }
    }

    //First breaking into tokens and save to the reviewer struct
    //If token is y then save one to reviewers feedback
    if(numLines == NUMBER_REVIEWERS){
        rewind(file);
        for(int i = 0; i < 10; ++i){
            fgets(tempString, MAX_STR, file);
            char *token = strtok(tempString, " ");
          
            strcpy(reviews[i].reviewer, token);
            
            char *tempTokenVal = strtok(NULL, " ");

            if(tempTokenVal[0] == 'y' || tempTokenVal[0] == 'Y'){
                reviews[i].feedback[0] = 1;
            }
            tempTokenVal = strtok(NULL, " ");
            if(tempTokenVal[0] == 'y' || tempTokenVal[0] == 'Y'){
                reviews[i].feedback[1] = 1;
            }
            tempTokenVal = strtok(NULL, " ");
            if(tempTokenVal[0] == 'y' || tempTokenVal[0] == 'Y'){
                reviews[i].feedback[2] = 1;
            }
        } 
        returnValue = 1;
    }else{
        printf("File not appropriate length\n");
        returnValue = 0;
    }
    fclose(file);
    return returnValue;

}

//Fourth Function

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]){

    //Most critial reviewer will have the lowest value
    int reviewerTotal[NUMBER_REVIEWERS] = {0};
    for(int i = 0; i < NUMBER_REVIEWERS; ++i){
        for(int j = 0; j < NUMBER_MOVIES; ++j){
           reviewerTotal[i] += reviews[i].feedback[j];
        }
    }

    //Set worstReviewer equal to the first total then compare, if lower value is found then it becomes new value of worstReviewer 
    int worstReview = reviewerTotal[0];
    for(int i = 1; i < NUMBER_REVIEWERS; ++i){
        if(worstReview > reviewerTotal[i]){
            worstReview = reviewerTotal[i];
        }
    }

    //If a review has a total equal to worstReview then we copy them back into most critial reviewers and we add to the counter
    int theCounter = 0;
    for(int i = 0; i < NUMBER_REVIEWERS; ++i){
        if(worstReview == reviewerTotal[i] ){
            strcpy(mostCriticalReviewers[i], reviews[i].reviewer);
            theCounter = theCounter + 1;
        }
    }

    return theCounter;
}

//Fifth Function 

int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR], const struct reviewStruct reviews[NUMBER_REVIEWERS], char mostRecommendedMovies[NUMBER_MOVIES][MAX_STR]){

    int mostRec[NUMBER_MOVIES] = {0};

    //Total the response for each movie, most recommened will have the highest value
    for(int i = 0; i < NUMBER_MOVIES; ++i){
        for(int j = 0; j < NUMBER_REVIEWERS; ++j){
            mostRec[i] += reviews[j].feedback[i];
        }
    }
    
    //Set goodOnes equal to first total and then compare
    int goodOnes = mostRec[0];
    for(int i = 1; i < NUMBER_MOVIES; ++i){
        if(goodOnes < mostRec[i]){
            goodOnes = mostRec[i];
        }
    }

    //If the number of good review equal the movie with the most good review count is increased and movie title is copied into mostRecommenedMovies 
    int theCount = 0;
    for(int i = 0; i < NUMBER_MOVIES; ++i){
        if(goodOnes == mostRec[i]){
            strcpy(mostRecommendedMovies[i], movies[i]);
            theCount = theCount + 1;
        }
    }

    return theCount;
}

//Sixth Function 

int predictMovie(const char movie[MAX_STR]){

    int thePrediction = 0;

    //Finding number of words
    int wordCount = 1;
    char movieClone[MAX_STR];
    strcpy(movieClone, movie);
    char *strtokPointerOne = strtok(movieClone, " ");

    while(strtok(NULL, " ") != NULL){
        wordCount = wordCount + 1;
    }

    //recopy as strtox messed up original movieClone
    strcpy(movieClone, movie);

    //Saving first elements to array and restarting strtox
    char tempArray[wordCount][MAX_STR];
    strtokPointerOne = strtok(movieClone, " ");
    strcpy(tempArray[0], strtokPointerOne);

    for(int i = 1; i < wordCount; ++i){
        strcpy(tempArray[i], strtok(NULL, " "));
    }
    
    //Finding number of words with even number character
    int numWithEvenCharacters = 0;
    for(int i = 0; i < wordCount; ++i){
        if( (strlen(tempArray[i]) % 2) == 0){
            numWithEvenCharacters += 1;
        }
    }

    //Finding is all words are the same length
    int sameSame = 1;
    int firstStringLen = strlen(tempArray[0]);
    for(int i = 1; i < wordCount; ++i){
        if(firstStringLen != strlen(tempArray[i])) {
            sameSame = 0;
            break;
        }
    }


    //Summing the result
    if(wordCount > 2){
        thePrediction -= 1;
    }if(wordCount == 1){
        thePrediction -= 2;
    }if(numWithEvenCharacters > 0){
        thePrediction += 1;
    }if(sameSame == 1){
        thePrediction += 2;
    }

    return thePrediction;
    
}

//Seventh Function 

int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]){

    //Finding the number of words
    int wordCount = 1;
    char movieClone[MAX_STR];
    strcpy(movieClone, movie);
    char *strtokPointerOne = strtok(movieClone, " ");

    while(strtok(NULL, " ") != NULL){
        wordCount = wordCount + 1;
    }

    //recopy as strtox messed up original movieClone
    strcpy(movieClone, movie);

    //Saving first elements to array and starting strtox
    char tempArray[wordCount][MAX_STR];
    strtokPointerOne = strtok(movieClone, " ");
    strcpy(tempArray[0], strtokPointerOne);

    //looping through strtok and saving to values of array
    for(int i = 1; i < wordCount; ++i){
        strcpy(tempArray[i], strtok(NULL, " "));
    }
  
    //Saving length of (i) string to position (i)
    for(int i = 0; i < wordCount; ++i){
        charCounts[i] = strlen(tempArray[i]);
    }

    return wordCount;
}