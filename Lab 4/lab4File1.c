#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] )
{
    
    int **sptr = 0;
    
    int num = 3;
    
    sptr = malloc (sizeof (int *) * num);
    
    for (int i = 0; i < num; i++) {
        sptr [i] = malloc (sizeof(int) * 4);
    }


    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            sptr [i][j] = 0;
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            sptr [i][j] =  sptr[i][j] + i * j + num;
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d \n", sptr [i][j]);
        }
    }


    //freeing data

    for (int i = 0; i < num; i++) {
        free(sptr [i]);
    }

    free(sptr);

    return 0;
}
