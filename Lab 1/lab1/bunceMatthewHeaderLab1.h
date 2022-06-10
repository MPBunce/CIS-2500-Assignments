/**********************************************************
Student Name: Matthew Bunce Email Id: mbunce@uoguelph.ca
Due Date: January 22nd, 2021 Course Name: CIS*2500 Lab 1
 I have exclusive control over this submission via my password.
 By including this statement in this header comment, I certify that:
 1) I have read and understood the University policy on academic
 integrity;
I assert that this work is my own. I have appropriately acknowledged
any and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared
by me specifically for this course.
 **********************************************************/
#define SIZE 25
#define NUM_EMP 3


/* definition of an employee record*/
typedef struct employee
{
 char fname[20];
 char lname[20];
 int id;
 char dependents [3][20]; // assume that no employees can have more
 // than 3 registered dependents
} Employees;

//Function Prototypes
void printEmployees(Employees[NUM_EMP], int);
void saveEmployees(Employees[NUM_EMP], int, char[SIZE]);
int loadEmployees(Employees[NUM_EMP], char[SIZE]);
void swapEmployees(Employees*, Employees*);