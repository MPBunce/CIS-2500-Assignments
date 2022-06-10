#include "fleschIndex.h"

int main(int argc, char *argv[]){

    //Calling my functions
    char *stringFile = readFile(argv[1]);
    
    int theNumWords = numWords(stringFile);

    int numSentence = numSentences(stringFile);

    int numSyllable = numSyllables(stringFile);

    //This is else statments is here for if the file is NULL or spelt wrong, error message will be displayed from readFile function
    //However as these functions return ints, which are zero if no file is read, this causes issues in caclualteFleschIndex
    //"Floating Point Exception" will be displayed without this as we divide by both numWords and numsentences in this function
    //Dividing by zero causes that error, so if either are equal to zero its because the file was NULL so we dont go to these functions and nothing concerning the Flesch score is printed

    if(theNumWords == 0 || numSentence == 0){

        return 0;

    }else{

        int indexNum = calculateFleschIndex(numSyllable, theNumWords, numSentence);
    
        outputFormattedFleschScores(numSyllable, theNumWords, indexNum, numSentence);

    }

}