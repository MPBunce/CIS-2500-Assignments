#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList){

    //taking in fileName

    char fileName[50] = "";
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "w+");

    //Writes elements to a file

    while(tweetList != NULL){

        fprintf(file, "%d %s %s\n", tweetList->id, tweetList->user, tweetList->text);
        tweetList = tweetList->next;

    }

    fclose(file);
    printf("Output Successful!\n");

}