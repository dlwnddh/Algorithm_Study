// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int T;
int H;
int W;
int N;
int lengths[1000];
int maxl = -1; // Maximum value in lengths[] array


int min(int a, int b){
    return (a < b) ? a : b;
}


void initlengths(){
    maxl = -1;
    for(int i = 0; lengths[i] != 0; i++) lengths[i] = 0;
}


void gettc(){
    scanf("%d", &T);
}


void getinput(){
    scanf("%d %d %d", &H, &W, &N);
    for(int x = 0; x < N; x++){
        char temp[1000] = { 0, };
        scanf("%s", &temp);
        lengths[x] = strlen(temp);
        if(maxl < lengths[x]) maxl = lengths[x];
    }
}


int valid(int n){
    int maxcollen = W / n;
    int maxcolnum = H / n;
    int currentcolnum = 1;
    int currentcollen = 0;
    for(int i = 0; i < N; i++){
        int lwordnow = lengths[i];
        // Adding the word on "currentcol"
        if(currentcollen == 0){ 
            currentcollen += lwordnow;
        }
        else{
            currentcollen += (lwordnow + 1);
        }

        // After the addition of word, check "currentcollen"
        if(currentcollen > maxcollen){
            currentcollen = lwordnow;
            currentcolnum++;
        }


        if(currentcolnum > maxcolnum) return 0;
    }
    return 1;
}


int run(){
    for(int goal = min(H, W/maxl); goal > 0; goal--) if(valid(goal)) return goal;
    return 0;
}


int main(void){
    gettc();
    for(int tc = 1; tc <= T; tc++){
        initlengths();
        getinput();
        printf("#%d %d\n", tc, run());
    }
return 0;}