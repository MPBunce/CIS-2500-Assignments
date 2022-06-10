#include "headerA3.h"

void countStopWords(tweet * tweetList){

    int numTweets = 1;
    int numStopWords = 0;
    tweet * temp = tweetList;
    tweet * tempTwo = tweetList;

    printf("\n");

    //Counting number of tweets
    while( (temp->next) != NULL){

        numTweets += 1;
        temp = (temp->next);

    }

    int x = 0;

    //copy string for strtok purposes, then loop passing tokens into the tokenCompare function

    for(int i = 0; i < numTweets; ++i){

        int size = strlen(tempTwo->text) - 1;
        char copyString[size];
        strcpy(copyString, tempTwo->text);


        char *token;
        token = strtok(copyString, " ");
        
        while(token != NULL){
           
            x += tokenCompare(token);
            token = strtok(NULL, " ");

        }

        tempTwo = tempTwo->next;

    }
    numStopWords += x;

    //printing results to user

    printf("Across %d tweets, %d stop words were found.\n\n", numTweets, numStopWords);
}