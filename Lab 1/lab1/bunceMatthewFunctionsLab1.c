#include "bunceMatthewHeaderLab1.h"
#include<stdio.h>
#include<string.h>

//First Function

void printEmployees(Employees employeeArray[NUM_EMP], int c){

    //Looping through the struct and print each element of it

    for(int i = 0; i < c; ++i){
        printf("First Name: %s\n", employeeArray[i].fname);
        printf("Last Name %s\n", employeeArray[i].lname);
        printf("ID: %d\n", employeeArray[i].id);
        printf("The Dependants Are:\n");

        //Looping through dependents, we know there cant be nore than 3 so j < 3

        for(int j = 0; j < 3; ++j){
            printf("%s\n", employeeArray[i].dependents[j]);
        }
    }

}

//Second Function 

void saveEmployees(Employees employeeArray[NUM_EMP], int c, char file[SIZE]){

    //Open new file with W+, printed w new line after so each element was diplayed on its own line
    FILE *f = fopen(file, "w+");
    for(int i = 0; i < c; ++i){
        
        //Cycling through elements of struct and printing them
        fwrite(employeeArray[i].fname, 1, strlen(employeeArray[i].fname), f);
        fwrite("\n", 1, 1, f);
        fwrite(employeeArray[i].lname, 1, strlen(employeeArray[i].lname), f);
        fwrite("\n", 1, 1, f);

        //Temporty String to Store ID into as you cant write an int 
        char tempString[10] = "";

        //Turning int to string simlar to printf
        sprintf(tempString, "%d", employeeArray[i].id);
        
        //Writing tempString into the file
        fwrite(tempString, 1, strlen(tempString), f);
        fwrite("\n", 1, 1, f);
        for(int j = 0; j < 3; ++j){
            fwrite(employeeArray[i].dependents[j], 1, strlen(employeeArray[i].dependents[j]), f);
            fwrite("\n", 1, 1, f);
        }
    }   
    fclose(f);
}

//Third Function

int loadEmployees(Employees employeeArray[NUM_EMP], char file[SIZE]){


    int countEmp = 0;

    FILE* f = fopen(file, "r");
    if(f != NULL){
        while(1){

            //If first line is null the loop breaks

            void *firstLine;
            firstLine = fgets(employeeArray[countEmp].fname, 20, f);
            if(firstLine == NULL){
                break;
            }
            fgets(employeeArray[countEmp].lname, 20, f);
            char tempString[20] = "";
            fgets(tempString, 20, f);
            fscanf(f, "%d", &(employeeArray[countEmp].id));
            for(int j = 0; j < 3; ++j){
                fgets(employeeArray[countEmp].dependents[j], 20, f);
                

            }    
            countEmp = countEmp + 1;
            
        }
    }
    else{
        printf("file is empty");
    }
    fclose(f);

    printf("Number of Employee Records Loaded: %d\n", countEmp);

    return countEmp;
}


void swapEmployees(Employees *firstEmployee, Employees *secondEmployee){

    //Making temporary employee and assigning employee data 
    Employees tempEmp = {0};

    strcpy(tempEmp.fname, firstEmployee->fname);
    strcpy(tempEmp.lname, firstEmployee->lname);
    tempEmp.id = firstEmployee->id;
    strcpy(tempEmp.dependents[0], firstEmployee->dependents[0]);
    strcpy(tempEmp.dependents[1], firstEmployee->dependents[1]);
    strcpy(tempEmp.dependents[2], firstEmployee->dependents[2]);

    //Copying second employee into first employee
    strcpy(firstEmployee->fname, secondEmployee->fname);
    strcpy(firstEmployee->lname, secondEmployee->lname);
    firstEmployee->id = secondEmployee->id;
    strcpy(firstEmployee->dependents[0], secondEmployee->dependents[1]);
    strcpy(firstEmployee->dependents[1], secondEmployee->dependents[2]);
    strcpy(firstEmployee->dependents[2], secondEmployee->dependents[3]);

    //Copying temp employee, which equal first employee, into second employee
    strcpy(secondEmployee->fname, tempEmp.fname);
    strcpy(secondEmployee->lname, tempEmp.lname);
    secondEmployee->id = tempEmp.id;
    strcpy(secondEmployee->dependents[0], tempEmp.dependents[1]);
    strcpy(secondEmployee->dependents[1], tempEmp.dependents[2]);
    strcpy(secondEmployee->dependents[2], tempEmp.dependents[3]);

}