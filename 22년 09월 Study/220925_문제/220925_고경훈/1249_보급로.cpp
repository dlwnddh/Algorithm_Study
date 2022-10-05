#include <iostream>
#include <queue>
#define BIG 2147483647

using namespace std;

struct node{
    int y;
    int x;
    int val;
};

struct fuck_off{
    bool operator()(node a, node b){
        return a.val > b.val;
    };
};

priority_queue<node, vector<node>, fuck_off> pq;

int map[100][100] = { 0, };
int dijk[100][100] = { BIG, };
int N;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};


void init(){
    for(int y = 0; y < N; y++) for(int x = 0; x < N; x++){
        map[y][x] = 0;
        dijk[y][x] = BIG;
    }
    N = 0;
    while(!pq.empty()){
        pq.pop();
    }
}


bool outofmap(int y, int x){
    if( y >= N ||
        y < 0 ||
        x >= N ||
        x < 0) return true;
    else return false;
}


int main(){
    int TC = 0;
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        // data input phase
        scanf("%d", &N);
        for(int y = 0; y < N; y++) for(int x = 0; x < N; x++) scanf("%1d", map[y][x]);
        // **** //

        // Dijkstra phase
        pq.push({0, 0, 0}); // indicates that the algorithm would start from 0, 0
        dijk[0][0] = 0;
        while(!pq.empty()){
            node now = pq.top();
            pq.pop();
            if(now.val > dijk[now.y][now.x]) continue;
            for(int i = 0; i < 4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                if(outofmap(ny, nx)) continue;
                int newcost = dijk[now.y][now.x] + map[ny][nx];
                if(dijk[ny][nx] <= newcost) continue;
                dijk[ny][nx] = newcost;
                pq.push({ny, nx, newcost});
            }
        }
        // **** //

        // resulting phase
        printf("#%d ", tc);
        printf("%d\n", dijk[N - 1][N - 1]);
        if(tc < TC) init();
        else return 0;
        // **** //
    } // End of for loop(or single testcase)
} // End of main function