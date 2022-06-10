#include<stdio.h>
#include<string.h>
#include "bunceMatthewHeaderLab1.h"


int main(){

    //Used for testing purposes
    //Defining Employees

    Employees empArray[NUM_EMP] = {0};

    strcpy(empArray[0].fname, "John");
    strcpy(empArray[0].lname, "Wall");
    empArray[0].id = 1;
    strcpy(empArray[0].dependents[0], "Catch");
    strcpy(empArray[0].dependents[1], "The");
    strcpy(empArray[0].dependents[2], "Cat");

    strcpy(empArray[1].fname, "Paul");
    strcpy(empArray[1].lname, "David");
    empArray[1].id = 2;
    strcpy(empArray[1].dependents[0], "Watch");
    strcpy(empArray[1].dependents[1], "No");
    strcpy(empArray[1].dependents[2], "Dog");

    strcpy(empArray[2].fname, "Penny");
    strcpy(empArray[2].lname, "Poggers");
    empArray[2].id = 3;
    strcpy(empArray[2].dependents[0], "Pass");
    strcpy(empArray[2].dependents[1], "A");
    strcpy(empArray[2].dependents[2], "Parrot");

    //Defining other variables

    int x = NUM_EMP;
    char p[] = "practice"; 

    //Calling Functions And Doing Stuff 

    printEmployees(empArray, x);
    saveEmployees(empArray, x, p);
    loadEmployees(empArray, p);
    swapEmployees(&empArray[0], &empArray[1]);
    
    //Printing Again to verifiy the swap occured
    printEmployees(empArray, x);

    return 0;
}