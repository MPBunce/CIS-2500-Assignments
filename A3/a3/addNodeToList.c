#include "headerA3.h"

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