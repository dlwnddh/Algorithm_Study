#include <iostream>
#include <queue>
#define BIG 2147483647

struct node{
    int y;
    int x;
    int val;
};

int map[100][100] = { 0, };
int dijk[100][100] = { BIG, };
int N;
const int dY[4] = {-1, 0, 1, 0};
const int dX[4] = {0, 1, 0, -1};

void init(){
    for(int y = 0; y < N; y++) for(int x = 0; x < N; x++){
        map[y][x] = 0;
        dijk[y][x] = BIG;
    }
    N = 0;
}

int main(){
    int TC = 0;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &N);
        for(int y = 0; y < N; y++) for(int x = 0; x < N; x++) scanf("%1d", map[y][x]);
        // End of getting input data


        // dijkstra ?????
        printf("#%d ", tc);

        init();
    } // End of single testcase


return 0;} // End of main function