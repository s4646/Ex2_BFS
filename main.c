#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_mat.h"
#define ROWS 10
#define COLS 10


int A(int *mat){
    int a;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf(" %d", &mat[i*10 + j]); // equals to *(mat + i*10 + j)
        }
    }
    return 0;
}

int B(int mat[10][10]){
    int i, j;
    scanf(" %d %d", &i,&j);
    int visit[10] = {-1};
    int index=0, pointer=1;
    visit[index] = i;
    bool route=true;

    while(route && index < 10){
        int tmp = visit[index];
        for(int k = 0 ; k<10 ; k++){
            if(mat[tmp][k]) {
                bool kVisited = false;
                for(int m = 0 ; m<pointer ; m++){
                    if(visit[m]==k){
                        kVisited = true;
                    }
                }
                if(!kVisited){
                visit[pointer]=k;
                pointer++;
                }
            }
        }
        if(visit[index]==-1){
            route=false;
        }
        for(int m = 0 ; m<10 && visit[0]!=j ; m++){
            if(visit[m]==j)
                return 1;
        }
        index++;
    }
    return 0;
}

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
            if(B(mat))
            {
                printf("True");
            }
            else
            {
                printf("False");
            }
            printf("\n");
        }
        if (c=='D')
        {
            break;
        }
    } while (c!=EOF);
    
    printMat(mat[0]);

    return 0;
}




