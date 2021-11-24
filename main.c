#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_mat.h"


int A(int mat[10][10], char* str){

    for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            mat[i][j] = str[10*i + j];
        }
    }
    return mat[10][10];
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

int temp() {

int matrix[10][10] = {{0,3,1,0,0,2,0,0,0,0}, {3,0,1,0,0,0,0,0,0,0}, {1,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,5,0,0}, {0,0,0,0,0,0,0,4,1,1}, {2,0,0,0,0,0,2,0,0,0},
                      {0,0,0,0,0,2,0,0,0,0}, {0,0,0,5,4,0,0,0,0,2}, {0,0,0,0,1,0,0,0,0,0},
                      {0,0,0,0,1,0,0,0,0,0}};
if(B(6,2,matrix)){
    printf("true\n");
}
else{
    printf("false\n");
}

return 0;
}

int main(){

    char c;
    int mat[10][10];
    while(scanf("%s ", &c) != EOF){
        if(c=='A'){
            //A(mat);
            continue;
        }
        if(c=='B'){
            int i,j;
            scanf("%d %d", &i,&j);
            if(B(i,j,mat)){
                printf("True");
            }
            else{
                printf("False");
            }
        }
        if(c=='C'){
            continue;
        }
        if(c=='D'){
            break;
        }
    }
}




