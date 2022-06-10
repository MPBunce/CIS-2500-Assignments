#include "headerA4.h"

void enqueue(tweet ** head, tweet ** tail, tweet * node){

    //adding node to end of list or beginning if empty

    if(*head == NULL){

        *head = node;

    }else{

        tweet *pointerTail = *tail;
        pointerTail->next = node;

    }
    

}

void dequeue(tweet ** head, tweet ** tail){

    //advancing list and freeing node

    if(tail == NULL){

        free(head);

    }else{

        tweet * oldHead = *head;
        *head = (*head)->next;
        free(oldHead);

    }



}

int isEmpty(tweet * head){

    int isEmpty = 0;

    //if head is null return 1

    if(head == NULL){

        isEmpty = 1;

    }

    return isEmpty;
}

void printQueue(tweet * head){

    printf("\n");

    //while head isnt null print head

    while(head != NULL){

        printf("%d: Created by %s: %s\n", head->id, head->user, head->text);
        head = head->next;

    }

    printf("\n");

}