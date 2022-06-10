/*
 Student Name: Matthew Bunce
 Student ID: 1000232
 Due Date: April 6th, 2021
 Course: CIS*2500
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct microtweet {
    int id; //non-unique integer value
    char user [51]; // the username / userid of the person who wrote the tweet
    char text [141]; // the text of the tweet
    struct microtweet *next; //dynamic connection to the next tweet
} tweet;

//Prototypes

void enqueue (tweet ** head, tweet ** tail, tweet * node);
void dequeue (tweet ** head, tweet ** tail);
int isEmpty (tweet * head);
void printQueue (tweet * head);
void sortID (tweet ** head, tweet ** tail);
void reverse (tweet ** head, tweet ** tail);
void sortUsername (tweet ** head, tweet ** tail);

//Prototypes I Made

tweet * createTweet(tweet * tweetList);
void addNodeToList(tweet**tweetList, tweet * node);
tweet * createNode();
void bubbleSortID(int numTweets, tweet ** nodeArray);
void bubbleSortUserName(int numTweets, tweet ** nodeArray);