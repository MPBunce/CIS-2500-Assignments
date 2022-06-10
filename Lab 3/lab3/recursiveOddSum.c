#include "header.h"

int recursiveSumNOdd(int n){

    int theReturn = 0;

    //less than or equal to one just return n else two times that number take away one plus the previous value for the total 

    if(n <= 1){
        theReturn = n;
    }else{
        
        theReturn = n*2 - 1 + recursiveSumNOdd(n - 1);
        
    }
    
    return theReturn;

}

