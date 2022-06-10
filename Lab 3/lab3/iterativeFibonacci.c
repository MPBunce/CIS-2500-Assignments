#include "header.h"

int iterativeFibonacci(int n){

    //Variables
    int x = 0;
    int theTotal = 0;
    int tempOne = 1;
    int tempTwo = 0;

    //if returns inital values for appropriate cariables else loops through
    if(n == 0){
        x = 0;
    }if(n == 1){
        x = 1;
    }else{

        for(int i = 0; i < n; ++i){

            //add two previous together new first val equal val two the new second val equal the total

            theTotal = tempOne + tempTwo;

            tempOne = tempTwo;
            tempTwo = theTotal;

        }

        x = theTotal;

    }

    return x;
    
}
