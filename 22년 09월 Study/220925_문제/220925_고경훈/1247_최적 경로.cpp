// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct coord {
    int x;
    int y;
};

int TC;
int N;
coord company;
coord home;
coord customer[11];
coord emptycrd = { 0, 0 };
bool used[11] = { false, };


int min(int a, int b){
    return (a > b) ? b : a;
}


void initializer() {
    N = 0;
    company = emptycrd;
    home = emptycrd;
    for (int i = 0; i < 11; i++) {
        customer[i] = emptycrd;
        used[i] = false;
    }
}


int dist(coord a, coord b) {
    int result = 0;
    result += (a.x > b.x) ? a.x - b.x : b.x - a.x;
    result += (a.y > b.y) ? a.y - b.y : b.y - a.y;
    return result;
}


void getinput() {
    scanf("%d", &N);
    scanf("%d %d %d %d", &(company.x), &(company.y), &(home.x), &(home.y));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(customer[i].x), &(customer[i].y));
    }
}


void visit(coord c, int num, int sumlen, int* res){ // From the "c", 
    if(sumlen > *res) return;
    if(num == N){
        sumlen += dist(c, home);
        *res = min(*res, sumlen);
        return;
    }
    for(int i = 0; i < N; i++){
        if(!used[i]){
            used[i] = true;
            visit(customer[i], num + 1, sumlen + dist(c, customer[i]), res);
            used[i] = false;
        }
    }
}


int run() {
#define BIG 2147483647
    int result = BIG;
    visit(company, 0, 0, &result);
    return result;
}


int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        initializer();
        getinput();
        printf("#%d %d\n", tc, run());
    } // End of single testcase
    return 0;
}