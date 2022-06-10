#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList){

    printf("\n");

    //taking in file name

    char fileName[150] = "";
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");

    int x = 1;

    //taking data in from file, mallocing a new node and assigning data

    if(file != NULL){

        while(x > 0){

            tweet * newNode = (tweet *)malloc( sizeof(tweet) );
            newNode->next = NULL;

            //Can take in data w a scanf due to nature of comma sepration in csv file

            x = fscanf(file, "%d,%[^,],%[^\n]\n", &(newNode->id), newNode->user, newNode->text);
            
            //adding to new node

            if(newNode->id != 0){

                addNodeToList(tweetList, newNode);

            }
    
        }

        fclose(file);
        printf("Tweets imported!\n");

    }else{
        printf("An error occured loading Tweets, please try again\n");
    }

    printf("\n");
}