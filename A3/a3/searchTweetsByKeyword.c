#include "headerA3.h"
#include <ctype.h>

int searchTweetsByKeyword(tweet * tweetList){

    //taking in keyWord

    printf("\n");
    int numMatches = 0;
    char buffer[150] = "";
    printf("Enter a keyword to search: ");
    fgets(buffer, 150, stdin);

    //saving from buffer to corret size string

    int sizeKeyWord = strlen(buffer) - 1;
    buffer[strcspn(buffer, "\n")] = 0;
    char keyWord[ (sizeKeyWord) ];
    strcpy(keyWord, buffer);
    
    //loops through elements if letter doesnt match it breaks, if letter matches we go to the next ect.
    //if there is a match, match = 1 , break loop and print string
    
    while(tweetList != NULL){

        int sentenceLength = strlen(tweetList->text) - 1;
       

        for(int i = 0; i < (sentenceLength); ++i ){
            int match = 1;
            
            for(int j = 0; j < sizeKeyWord; ++j){
                
                
                if( tolower( keyWord[j] ) != tolower( (tweetList)->text[i + j] ) ){
                    
                    match = 0;
                    break;
                    
                    
                }
                
            }
        
        
            if(match == 1){
            printf("Match found for '%s': %s wrote: %s \n", keyWord, tweetList->user, tweetList->text);
            numMatches += 1;
            break;
            
            }

        }
        tweetList = tweetList ->next;

    }

    return numMatches;

}