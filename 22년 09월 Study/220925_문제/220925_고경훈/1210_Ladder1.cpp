// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[100][100] = { 0, };


bool outrange(int x){
    if(x < 0 || x >= 100) return true;
    return false;
}


int gogo(int y, int x){
    if(y == 0) return x;

    bool found = false;

    int nx = x + 1;
    if(outrange(nx)) {}
    else if(map[y][nx] == 1){
        map[y][x] = 0;
        return gogo(y, nx);
    }

    nx = x - 1;
    if(outrange(nx)) {}
    else if(map[y][nx] == 1){
        map[y][x] = 0;
        return gogo(y, nx);
    }

    return gogo(y - 1, x);
}


int main() {

//    freopen("input.txt", "r", stdin);
    int TC = 10;
    for (int tc = 1; tc <= TC; tc++) {
        int fuck = -1;
        scanf("%d", &fuck);
        int cursorY = 99;
        int cursorX = -1;
        for (int y = 0; y < 100; y++) for (int x = 0; x < 100; x++) {
            scanf("%d", &map[y][x]);
            if (map[y][x] == 2) cursorX = x;
        }


        printf("#%d %d\n", tc, gogo(cursorY, cursorX));
    } // End of single testcase
}