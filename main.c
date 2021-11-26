#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <limits.h>
#include "my_mat.h"
#define ROWS 10
#define COLS 10
//#define INFINITY INT_MAX


int A(int *mat);
int B(int i, int j, int mat[10][10]);
int C(int i, int j, int mat[10][10]);

void printMat(int *mat){

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", mat[i*10 + j]); // equals to *(mat + i*10 + j)
        }
    }
}

int main(){

    int mat[ROWS][COLS] = {{0}};
    char c;
    do
    {
        scanf(" %c", &c);
        if (c=='A')
        {
            A(mat[0]);
        }
        if (c=='B')
        {
            int i, j;
            scanf(" %d %d", &i,&j);
            if(B(i,j,mat))
            {
                printf("True");
            }
            else
            {
                printf("False");
            }
            printf("\n");
        }
        if (c=='C')
        {
            int i, j;
            scanf(" %d %d", &i,&j);
            int x = C(i,j, mat);
            if(!x)
            {
                printf("-1");
                printf("\n");
            }
            else
            {
                printf("%d", x);
                printf("\n");
            }
        }
        if (c=='D')
        {
            break;
        }
    } while (c!=EOF);
    
    //printMat(mat[0]);

    return 0;
}




