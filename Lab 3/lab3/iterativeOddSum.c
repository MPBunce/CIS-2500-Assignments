#include "header.h"

int iterativeSumNOdd(int n){

    int theReturn = 1;
    int tempOne = 1;
    
    //If n = 1 return 1 else add 2 to value then add to total and loop through
    if(n == 1){
        theReturn = tempOne;
    }else{
        for(int i = 0; i < n-1; ++i){
            tempOne += 2;
            theReturn += tempOne;
        }
    }

    return theReturn;
}
