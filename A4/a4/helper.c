#include "headerA4.h"

tweet * createTweet(tweet * tweetList){

    fflush(stdin);

    //Taking in new information

    tweet * newNode = (tweet *)malloc( sizeof(tweet) );
    printf("Enter a username: ");
    fgets(newNode->user, 51, stdin);

    printf("Enter the user's tweet: ");
    fgets(newNode->text, 141, stdin);

    newNode->user[strcspn(newNode->user, "\n")] = 0;
    newNode->text[strcspn(newNode->text, "\n")] = 0;

    //Calculating Unique User ID

    int sum = 0;
    int lengthUser = strlen(newNode->user);

    for(int i = 0; i < lengthUser; ++i){
        sum += newNode->user[i];
    }

    int lengthText = strlen(newNode->text);

    //Assigning to linkedList

    newNode->id = lengthText + sum;
    newNode->next = NULL;

    addNodeToList(&tweetList, newNode);

    return tweetList;

}

void addNodeToList(tweet**tweetList, tweet * node){

    //If tweetlist is null then node equals tweetlist

    if(*tweetList == NULL){
        *tweetList = node;
    }else{

        //else we save the head then advance until next is NULL then set that equal to

        tweet * head = *tweetList;

        while( head->next != NULL){
            head = head->next;
        }

        head->next = node;

    }

}

tweet * createNode(){

    printf("\n");
    fflush(stdin);

    //Taking in new information

    tweet * newNode = (tweet *)malloc( sizeof(tweet) );
    printf("Enter a username: ");
    fgets(newNode->user, 51, stdin);

    printf("Enter the user's tweet: ");
    fgets(newNode->text, 141, stdin);

    newNode->user[strcspn(newNode->user, "\n")] = 0;
    newNode->text[strcspn(newNode->text, "\n")] = 0;

    //Calculating Unique User ID

    int sum = 0;
    int lengthUser = strlen(newNode->user);

    for(int i = 0; i < lengthUser; ++i){
        sum += newNode->user[i];
    }

    int lengthText = strlen(newNode->text);

    //Assigning to linkedList

    newNode->id = lengthText + sum;
    newNode->next = NULL;

    return newNode;

}

void bubbleSortID(int numTweets, tweet ** nodeArray){

    tweet * bubbleTemp = NULL;
    
    for(int i = 0; i < numTweets - 1; ++i){


        for(int j = 0; j < numTweets - i - 1; ++j){


            if(nodeArray[j]->id > nodeArray[j+1]->id){
                
                bubbleTemp = nodeArray[j];
                nodeArray[j] = nodeArray[j+1];
                nodeArray[j+1] = bubbleTemp;

            }

        }

    }

}

void bubbleSortUserName(int numTweets, tweet ** nodeArray){

    tweet * bubbleTemp = NULL;

    for(int i = 0; i < numTweets - 1; ++i){


        for(int j = 0; j < numTweets - i - 1; ++j){


            if( tolower(nodeArray[j]->user[0]) > tolower(nodeArray[j+1]->user[0]) ){
                
                bubbleTemp = nodeArray[j];
                nodeArray[j] = nodeArray[j+1];
                nodeArray[j+1] = bubbleTemp;

            }

        }

    }

}