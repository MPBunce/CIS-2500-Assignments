#include "header.h"

int recursiveFibonacci(int n){

    int x = 0;

    //less than or equal 1 then just return that value
    //else we add the prevous two together this causes forking

    if(n <= 1){
        x = n;
    }else{
        x = recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
    return x;
}