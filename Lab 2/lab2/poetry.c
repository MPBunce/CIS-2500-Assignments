#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    
    //Variable
    int maxLineLength = 100;
    int lineSize = sizeof(char)*maxLineLength;
    int numLines = 1;

    char *poetryArray = (char* )malloc(lineSize);

    //Taking in user input with fgets vs gets as that causes overflow issues, 
    printf("Enter the poem:\n");
    char *x = fgets(poetryArray, maxLineLength, stdin);

    //while the input doesnt equal . it saved the new lines of max character length, new spaces added using realloc and memset to null
    while(*x != '.'){
        numLines += 1;
        poetryArray = (char *)realloc(poetryArray, numLines*lineSize);
        memset(poetryArray + (numLines-1)*lineSize, '\0', lineSize);
        x = fgets(poetryArray + (numLines-1)*lineSize, maxLineLength, stdin);
    }

    //variables for counting lines and numbers, creating another string array to store intingers for each lines
    int numberSize = sizeof(int);
    int mallocSize = numberSize*(numLines - 1);
    int numWords = 0;
    int *wordNumArray = (int *)malloc(mallocSize);

    //looping through lines of poetry array
    for(int i = 0; i < (numLines-1); ++i){
        
        //strtok to count the words per line
        int lineWordCount = 1;
        strtok(poetryArray + i*lineSize, " ");
        while(strtok(NULL, " ") != NULL){
            lineWordCount += 1;
        }

        //saving number of words per line to the new string array
        numWords += lineWordCount;
        *(wordNumArray + i) = lineWordCount;

    }
    int finalNumWords = numWords;
    int finalNumLines = (numLines - 1);

    //printing results

    printf("%d words on %d lines\n", finalNumWords, finalNumLines); 
    for(int i = 0; i < (numLines - 1); ++i){
        printf("%d ", *(wordNumArray + i));
    }
    printf("\n");
}
