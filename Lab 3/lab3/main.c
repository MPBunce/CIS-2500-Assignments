#include "header.h"

int main(){

    float timeOne = 0;
    float timeTwo = 0;
    float timeThree = 0;
    float timeFour = 0;
    int orderSeq = 0;

    printf("Enter the order to which you want to execute the Fibonacci and Odd Sum Sequences:\n");
    scanf("%d", &orderSeq);

    //Part a Functions
    clock_t end = clock();
    clock_t begin = clock();
    iterativeFibonacci(orderSeq);
    end = clock();
    timeOne += (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();    
    recursiveFibonacci(orderSeq);
    end = clock();
    timeTwo += (double)(end - begin) / CLOCKS_PER_SEC;

    //Part b Functions

    begin = clock();
    iterativeSumNOdd(orderSeq);
    end = clock();
    timeThree += (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    recursiveSumNOdd(orderSeq);
    end = clock();
    timeFour += (double)(end - begin) / CLOCKS_PER_SEC;

    //printing with requested format

    printf("Time to complete iterative Fibonacci of size %d: %f seconds.\n", orderSeq, timeOne);
    printf("Time to complete recursive Fibonacci of size %d: %f seconds.\n", orderSeq, timeTwo);
    printf("Time to complete iterative Sum_N_Odd of size %d: %f seconds.\n", orderSeq, timeThree);
    printf("Time to complete recursive Sum_N_Odd of size %d: %f seconds.\n", orderSeq, timeFour);

}