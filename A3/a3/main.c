#include "headerA3.h"


int main(){

    int x = 0;
    tweet * headTweet = NULL;
    char garbage[100] = "";

    while(x != 8){

        //printing the menu
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are “stop words”\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file \n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");

        //taking in user input
        printf("Choose a menu option: ");
        int scanfReturn = scanf("%d", &x);
        fgets(garbage, 100, stdin);
        fflush(stdin);

        //loop for the menu

        if(scanfReturn == 0){
            
            x = 0;
        
        }else if(x == 1){

            headTweet = createTweet(headTweet);
        
        }
        else if(x == 2){
            
            displayTweets(headTweet);

        }
        else if(x == 3){
            
            //This is here as otherwise there would be an unused varibale error
            int B = searchTweetsByKeyword(headTweet);
            printf("Number of tweets with keyword is: %d\n\n", B);
        }
        else if(x == 4){
            
            countStopWords(headTweet);

        }
        else if(x == 5){
            
            deleteTweet(&headTweet);

        }
        else if(x == 6){

            saveTweetsToFile(headTweet);

        }
        else if(x == 7){
            
            loadTweetsFromFile(&headTweet);

        }else{

            x = 8;
        }


    
    }

}