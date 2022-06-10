#include "gryphflix.h"
#include<stdio.h>
#include<string.h>

int main(){

    //Variables

    FILE *openFile;

    int M;
    char movieNames[NUMBER_MOVIES][MAX_STR] = {"","",""};

    //Testing First Function

    openFile = openFileForReading("movies.txt");

    //Testing Second Function

    M = readMovies(openFile, movieNames);

    printf("%d\n", M);
    for(int i = 0; i < 3; ++i){
        printf("%s", movieNames[i]);
    }

    //Testing Third Function

    struct reviewStruct theReviews[10] = {0};

    FILE *openFileTwo = openFileForReading("reviews.txt");

    readReviews(openFileTwo, theReviews);

   //Testing Fourth Function

    char criticalReviewers[NUMBER_REVIEWERS][MAX_STR] = {"", "", "", "", "", "", "", "", "", ""};
    int numCrit = 0;

    numCrit = getMostCriticalReviewers(theReviews, criticalReviewers);

   
    //Testing Fifth Function

    char recommendedMovies[NUMBER_MOVIES][MAX_STR] = {0};
    int numRec = 0;
    numRec = getMostRecommendedMovies(movieNames, theReviews, recommendedMovies);
    printf("%d\n", numRec);

    for(int i = 0; i < NUMBER_MOVIES; ++i){
        if(strlen(recommendedMovies[i]) == 0);
        printf("%s\n", recommendedMovies[i]);
    }

    //Testing 6th

    char testerString[MAX_STR] = "star wars";
    int amcStock = predictMovie(testerString);
    printf("Predicted Volitility: %d\n", amcStock);

    //Testing 7th

    int charCount[MAX_WORDS] = {0};
    char theString[MAX_STR] = "The Horse Jinglebells";

    int numOfWords = enumerateMovie(theString, charCount);
    printf("%d\n", numOfWords);

    
    for(int i = 0; i < MAX_WORDS; ++i){
        if(charCount[i] == 0){
            break;
        }
        printf("%d\n", charCount[i]);
        
    }
    
}
