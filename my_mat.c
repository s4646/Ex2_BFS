#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ROWS 10
#define COLS 10

int A(int *mat){

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf(" %d", &mat[i*10 + j]); // equals to *(mat + i*10 + j)
        }
    }
    return 0;
}

int B(int i, int j, int mat[10][10]){
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

int C(int i, int j, int mat[10][10]){
    if(!B(i,j, mat))
    {
        return -1;
    }
    int copy[10][10] = {{0}};
    int *ptr, *matrix;
    ptr = copy[0];
    matrix = mat[0];
    int max = -1;
    // copy matrix and get its max value
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(ptr+i*ROWS+j)=*(matrix+i*ROWS+j);
            if(max<*(matrix+i*ROWS+j))
            {
               max= *(matrix+i*ROWS+j);
            }
        }
    }
    // set matrix with max values

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(*(ptr+i*ROWS+j)==0 && (i!=j)){
                *(ptr+i*ROWS+j)=max+1;
            }
        }
    }
    // Floyd-Warshal algorithm
    for (int k = 0; k < ROWS; k++)
    {
        for (int m = 0; m < ROWS; m++)
        {
            for (int n = 0; n < ROWS; n++)
            {
                if(*(ptr+m*ROWS+n) > *(ptr+m*ROWS+k)+*(ptr+k*ROWS+n))
                {
                    *(ptr+m*ROWS+n) = *(ptr+m*ROWS+k)+*(ptr+k*ROWS+n);
                    
                }
            }
        }
    }
    return *(ptr+i*ROWS+j);
}