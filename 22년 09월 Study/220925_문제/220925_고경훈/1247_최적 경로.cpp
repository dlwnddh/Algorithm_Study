#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct coord{
    int x;
    int y;
};

int TC;
int N;
coord company;
coord home;
coord customer[11];
coord emptycrd = {0, 0};

void initializer(){
    N = 0;
    company = emptycrd;
    home = emptycrd;
    for(int i = 0; i < 11; i++){
        customer[i] = emptycrd;
    }
}

void getinput(){
    scanf("%d", &N);
    scanf("%d %d %d %d", &(company.x), &(company.y), &(home.x), &(home.y));
    for(int i = 0; i < N; i++){
        scanf("%d %d", &(customer[i].x), &(customer[i].y));
    }
}

int run(){


    return 0;
}


int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        initializer();
        getinput();

        printf("#%d %d\n", tc, run());
    } // End of single testcase


return 0;}      