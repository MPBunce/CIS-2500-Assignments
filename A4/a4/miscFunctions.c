#include "headerA4.h"

void sortID(tweet ** head, tweet ** tail){

    tweet * numTweets = *head;
    int numNodes = 1;

    //finding number of nodes

    while(numTweets->next != NULL){
    
        numNodes += 1;
        numTweets = numTweets->next;

    }

    //malloc space for node array

    tweet ** nodeArray = malloc(sizeof(tweet * )*numNodes);
    tweet * tempAssigner = *head;

    int counter = 0;

    //putting lined list into node array

    while( tempAssigner != NULL ){
        
        nodeArray[counter] = tempAssigner;
        tempAssigner = tempAssigner->next;
        counter += 1;

    }

    //Now we sort

    bubbleSortID(numNodes, nodeArray);

    //reconstructing linked list

    tweet * newList = nodeArray[0];
    *head = newList;
    int counterTwo = 0;

    while(counterTwo < numNodes - 1){
        
        nodeArray[counterTwo]->next = nodeArray[counterTwo + 1];
        counterTwo += 1;

    }

    //setting tail next equal to null and freeing array

    tweet * newTail = nodeArray[counterTwo];
    *tail = newTail;
    nodeArray[counterTwo]->next = NULL;
    free(nodeArray);

}

void reverse(tweet ** head, tweet ** tail){

    tweet * current = *head;
    tweet * next = NULL;
    tweet * previous = NULL;

    //loop to reverse list

    while(current != NULL){

        next = current->next;
        current->next = previous;
        previous = current;
        current = next;


    }

    //setting tail equal to head and head equal to the tail one list has been reversed

    *tail = *head;
    *head = previous;

}

void sortUsername(tweet ** head, tweet ** tail){

    tweet * numTweets = *head;
    int numNodes = 1;

    //finding number of nodes

    while(numTweets->next != NULL){
    
        numNodes += 1;
        numTweets = numTweets->next;

    }

    //making space for node array

    tweet ** nodeArray = malloc(sizeof(tweet * )*numNodes);
    tweet * tempAssigner = *head;

    int counter = 0;

    //putting lined list into node pointer array

    while( tempAssigner != NULL ){
        
        nodeArray[counter] = tempAssigner;
        tempAssigner = tempAssigner->next;
        counter += 1;

    }

    //Now we sort

    bubbleSortUserName(numNodes, nodeArray);

    //reconstructing the linked list
    //head is postion zero

    tweet * newList = nodeArray[0];
    *head = newList;

    int counterTwo = 0;

    while(counterTwo < numNodes - 1){
        
        nodeArray[counterTwo]->next = nodeArray[counterTwo + 1];
        counterTwo += 1;

    }

    //setting next position after last node equal to NULL

    tweet * newTail = nodeArray[counterTwo];
    *tail = newTail;
    nodeArray[counterTwo]->next = NULL;
    
    free(nodeArray);


}