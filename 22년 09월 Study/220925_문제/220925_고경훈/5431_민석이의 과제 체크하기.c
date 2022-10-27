// #define _CRT_SECURE_NO_WARNINGS
#define MX 101
#include <stdio.h>

int submitted[MX] = { 0, };

void init(){
    for(int i = 0; i < 101; i++) submitted[i] = 0;
}

void run(int N){
    for(int i = 1; i <= N; i++){
        if(!submitted[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int TC = 0;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        init();
        int N = 0;
        int K = 0;
        scanf("%d %d", &N, &K);
        for(int _ = 0; _ < K; _++){
            int fuck = 0;
            scanf("%d", &fuck);
            submitted[fuck] = 1;
        }
        printf("#%d ", tc);
        run(N);
    }
}