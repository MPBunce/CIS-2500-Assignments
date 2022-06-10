#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int vowelCompare(char myChar){

    int theVal = 0;
    int X = tolower(myChar);
    if(X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u' || X == 'y'){
        theVal = 1;
    }
    return theVal;
}

int main(){

    char tokenPointer[7] = "theee";
    int theLength = 7;
    int counter = 0;
    int totalSyls = 0;

    for(int i = 0; i < theLength-1; ++i){
        if( vowelCompare(tokenPointer[i]) == 1 && vowelCompare(tokenPointer[i+1]) == 0){
            counter += 1;
        }
    }

    
    if( vowelCompare(tokenPointer[theLength - 2]) == 1 && tokenPointer[theLength - 1] == 'e' ){
        counter += 1;
    }if( vowelCompare(tokenPointer[theLength - 1]) == 1 && tokenPointer[theLength - 1] != 'e'){
        counter += 1;
    }if(counter == 0){
        counter += 1;
    }

    totalSyls += counter;
    counter = 0;
    printf("%d\n", totalSyls);

}