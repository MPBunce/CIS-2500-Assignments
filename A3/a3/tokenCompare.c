#include "headerA3.h"

int tokenCompare(char * token){

    int choice = 0;

    //if it equals specified token we return 1

    if( strcmp(token, "a") == 0 || strcmp(token,"an") == 0 || strcmp(token, "and") == 0 || strcmp(token, "are") == 0 || strcmp(token,"as") == 0 || strcmp(token,"at") == 0 || strcmp(token,"be") == 0 || strcmp(token,"by") == 0 || strcmp(token,"for") == 0 || strcmp(token,"from") == 0 || strcmp(token,"has") == 0 || strcmp(token, "he") == 0 || strcmp(token,"in") == 0 || strcmp(token, "is") == 0 || strcmp(token,"it") == 0 || strcmp(token,"its") == 0 || strcmp(token, "of") == 0 || strcmp(token,"on") == 0 || strcmp(token,"that") == 0 || strcmp(token,"the") == 0 || strcmp(token,"to") == 0 || strcmp(token,"was") == 0 || strcmp(token,"were") == 0 || strcmp(token,"will") == 0 || strcmp(token,"with") == 0){
       
        choice = 1;

    }

    return choice;
}