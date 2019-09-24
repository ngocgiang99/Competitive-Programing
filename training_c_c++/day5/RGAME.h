#include<stdio.h>
#include<stdlib.h>

void finishTheGame(int ok){
    if (ok) printf("Win\n");
    else printf("Lose\n");
    //exit(0);
}

int ___n, ___limit = 1000000000, ___flag = 2;
int ___gameStarted = 0;

int get_n(int n){
    ___n = n;
    ___limit = ___n-1;
    ___gameStarted = 1;
    ___flag = 2;
    return ___n;
}

int play(int x){
    if (!___gameStarted || ___flag==1 || x>___limit || x<1) finishTheGame(0);
    ___n -= x;
    if (___n == 0) {
        finishTheGame(1); 
        return -1;
    }
    ___limit = x< ___n?x:___n;
    ___flag = 1;
    return 0;
}

int get_x(){
    // printf("%d %d\n", ___n, ___flag);
    if (!___gameStarted || ___flag==0) finishTheGame(0);
    int x = rand() % (___limit) + 1;
    ___n -= x;
    // printf("%d %d\n", ___n, ___flag);
    if (___n == 0) {
        finishTheGame(0);
        return -1;
    }
    ___limit = x< ___n?x:___n;
    ___flag = 0;
    return x;
}
