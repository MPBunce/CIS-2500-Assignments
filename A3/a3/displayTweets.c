#include "headerA3.h"

void displayTweets(tweet * tweetList){

    printf("\n");

    //while list isnt null print

    while(tweetList != NULL){

        printf("%d: Created by %s: %s\n", tweetList->id, tweetList->user, tweetList->text);
        tweetList = tweetList->next;

    }

    printf("\n");

}