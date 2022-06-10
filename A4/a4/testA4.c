#include "headerA4.h"

int main(){

    //Initalizing Variables
    int x = 0;
    tweet * headTweet = NULL;

    x = isEmpty(headTweet);

    //testing is empty

    if(x == 1){
        printf("\nThe queue is empty!\n");
    }

    x = isEmpty(headTweet);

    if(x == 1){
        printf("The queue is empty!\n");
    }

    x = isEmpty(headTweet);

    if(x == 1){
        printf("The queue is empty!\n\n");
    }

    printf("Tested isEmpty being empty 3 times\n");
    printf("Lets make some nodes!!\n\n");

    //making linked list

    for(int i = 0; i < 5; ++i){

        headTweet = createTweet(headTweet);

    }


    printQueue(headTweet);
    x = isEmpty(headTweet);

    //testing is empty

    if(x == 0){
        printf("The queue has contents!\n");
    }

    x = isEmpty(headTweet);

    if(x == 0){
        printf("The queue has contents!\n");
    }

    x = isEmpty(headTweet);

    if(x == 0){
        printf("The queue has contents!\n\n");
    }

    printf("Tested isEmpty having contents 3 times\n");

    tweet * tailFinder = headTweet;

    while(tailFinder->next != NULL){

        tailFinder = tailFinder->next;

    }

    tweet * newNode;

    //loop testing remaning functions three times

    for(int i = 1; i < 4; ++i){

        newNode = createNode();
        
        printf("\nEnqueue node iteration %d\n", i);
        enqueue(&headTweet, &tailFinder, newNode);
        printQueue(headTweet);
        printf("Sort ID iteration %d\n", i);
        sortID(&headTweet, &tailFinder);
        printQueue(headTweet);
        printf("Dequeue node iteration %d\n", i);
        dequeue(&headTweet, &tailFinder);
        printQueue(headTweet);
        printf("Sort username iteration %d\n", i);
        sortUsername(&headTweet, &tailFinder);
        printQueue(headTweet);
        printf("Reverse list iteration %d\n", i);
        reverse(&headTweet, &tailFinder);
        printQueue(headTweet);
        

    }

    //times tested
    printf("Function test summary:\n");
    printf("Enqueue tested 3 times\n");
    printf("Dequeue tested 3 times\n");
    printf("isEmpty tested 6 times\n");
    printf("printQueue tested 16 times\n");
    printf("sortID tested 3 times\n");
    printf("sortUsername tested 3 times\n");
    printf("reverse tested 3 times\n\n");
    
    //Freeing so no memory leaks
    tweet * toFree;
    while(headTweet != NULL){
        toFree = headTweet;
        headTweet = headTweet->next;
        free(toFree);
    }

}