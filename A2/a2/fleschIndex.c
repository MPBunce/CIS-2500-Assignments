#include "fleschIndex.h"

char * readFile(char *filename){

    //Open File and find size, the malloc that size

    FILE *theFile = fopen(filename, "r");
    char *fileString;

    if(theFile != NULL){

        //mallocing size of file

        fseek(theFile, 0, SEEK_END);
        int mallocSize = ftell(theFile);
        rewind(theFile);

        fileString = (char*)malloc(mallocSize);
        fread(fileString, 1, mallocSize, theFile);

    }else{

        //error message
        printf("Error reading the file, please double check the file has content and filename was spelt correctly\n");
    }

    return fileString;
}

int numWords(char * theString){

    int theTotal = 1;
    char *tempString;
    int theSize = strlen(theString);

    tempString = (char*)malloc(theSize);
    strcpy(tempString, theString);

    //count words with copied string as strtok mess with original string
    //Find token based of \n and " " as delimtere

    strtok(tempString, " ");
    while( strtok(NULL, " \n") != NULL){
        theTotal += 1;
    }

    return theTotal;
}

int numSentences(char * theString){

    int theSize = strlen(theString);
    int sentenceNumber = 0;

    //If char equals the accepted sentence indicator it adds to total count

    for(int i = 0; i < theSize; ++i){
        if(theString[i] == '.' || theString[i] == '?' || theString[i] == '!' || theString[i] == ':' || theString[i] == ';'){
            sentenceNumber += 1;
        }
    }
    return sentenceNumber;
}

int vowelCompare(char myChar){

    //Returns 1 if the char is a vowel

    int theVal = 0;
    int X = tolower(myChar);
    if(X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u' || X == 'y'){
        theVal = 1;
    }
    return theVal;
}

int numSyllables(char * theString){

    int theSize = strlen(theString);
    char *tempString;
    tempString = (char*)malloc(theSize);
    strcpy(tempString, theString);

    char * tokenPointer = strtok(tempString, " \n");
    int counter = 0;
    int totalSyls = 0;

    //Loop though the remaining tokens
    //look at switch from vowel to constant then add
    //three exception statments to cover the rules with e and other issues
    //loop for length -1 as otherwise coming to the last term will cause issues
    
    while(tokenPointer != NULL){

        int theLength = strlen(tokenPointer);

        for(int i = 0; i < theLength-1; ++i){
            if( vowelCompare(tokenPointer[i]) == 1 && vowelCompare(tokenPointer[i+1]) == 0){
                counter += 1;
            }
        }
        
        if( vowelCompare(tokenPointer[theLength - 2]) == 1 && tokenPointer[theLength - 1] == 'e'){
            counter += 1;
        }if( vowelCompare(tokenPointer[theLength - 1]) && tokenPointer[theLength - 1] != 'e'){
            counter += 1;
        }if(counter == 0){
            counter += 1;
        }

        totalSyls += counter;
        counter = 0;
        tokenPointer = strtok(NULL, " \n");

    }

    return totalSyls;
}

int calculateFleschIndex(int syllables, int words, int sentences){

    //calculationg FleschIndex and returning rounded final value w the 0.5
    int theFinal = 0;
    float calculatedFlechIndex = 0;
    float varOne = (syllables/words);
    float varTwo = (words/sentences);
    calculatedFlechIndex = 206.835 - (varOne*84.6) - (varTwo*1.015);
    theFinal = calculatedFlechIndex + 0.5;
 
    return theFinal;
}

void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount){

    //outputting the given intigers in requested format

    printf("Flesch Index = %d\n", fleshIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentenceCount);

}
