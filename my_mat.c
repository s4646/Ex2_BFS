#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




int A(int mat[10][10]){

char c[10];
    while(scanf("%s ", &c)){
        for(int i=0 ; i<10 ; i++) {

        }
    }
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
