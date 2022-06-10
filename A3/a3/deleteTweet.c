#include "headerA3.h"

void deleteTweet(tweet ** tweetList){

    int numTweets = 1;
    int numToDelete = 0;
    tweet * temp = *tweetList;
    
    printf("\n");

    if(*tweetList == NULL){
        printf("Currently there are no tweets\n");
    }else{

        //Counting number of tweets and asking for user input

        while( (temp->next) != NULL){

            numTweets += 1;
            temp = (temp->next);

        }

        printf("Currently there are %d tweets.\n", numTweets);
        printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", numTweets);
        scanf("%d", &numToDelete);
        
        //To delete first tweet just advance to the second and set it as the head

        if(numToDelete == 1){

            tweet * oldHead = *tweetList;
            *tweetList = (*tweetList)->next;
            free(oldHead);
            

            //To delete the last tweet advance to the second to last and set next equal to NULL

        }else if(numToDelete == numTweets){
            
            tweet * secondLast = *tweetList;

            for(int i = 0; i < numToDelete - 2; ++i){
                secondLast = secondLast->next;
            }

            free(secondLast->next);
            secondLast->next = NULL;
            

            //for middle tweets set previous next equal to the next node

        }else{

            tweet * preNode = *tweetList;
            tweet * postNode = *tweetList;

            for(int i = 0; i < numToDelete - 2; ++i){
                preNode = preNode->next;
            }

            for(int i = 0; i < numToDelete; ++i){
                postNode = postNode->next;
            }

            free(preNode->next);
            preNode->next=postNode;



        }



    }  

    printf("\n");

}