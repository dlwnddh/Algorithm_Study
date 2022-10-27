// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define E_12 0.000000000001 // 1E-12
#define E_15 (E_12 * 0.001) // 1E-15

struct obj {
    int x;
    int m;
};
using namespace std;
typedef double db;

int N;
db F;
obj obs[10];
db bdps[9];
db recentsF;
bool isfirstrcsv = false;


db force(db x, int n) { // objnumber n
    // <- direction force is (-)
    // -> direction force indicated by (+)

    db amount = obs[n].m / ((x - obs[n].x) * (x - obs[n].x));
    if (obs[n].x < x) return (-1) * amount;
    else return amount;
}


db netforce(db x) {
    db netforce = 0;
    for (int i = 0; i < N; i++) {
        netforce += force(x, i);
    }
    return netforce;
}


void sortobs() {
    struct fuck_yeah {
        bool operator()(obj a, obj b) {
            return a.x > b.x;
        }
    };
    priority_queue<obj, vector<obj>, fuck_yeah> pq;
    for (int i = 0; i < N; i++) {
        pq.push(obs[i]);
    }
    for (int i = 0; i < N; i++) {
        obj temp = pq.top();
        obs[i] = temp;
        pq.pop();
    }
}


db bnr(db L, db R) {
    db RL = R - L;
    db z = (L + R) / 2;
    db sF = netforce(z);
    db dif_now_before = sF - recentsF;
    if (
        !isfirstrcsv &&
        (-1) * E_15 < dif_now_before &&
        dif_now_before < E_15
        ) {
        return z;
    }
    recentsF = sF;
    isfirstrcsv = false;
    if (RL < E_12) return z;
    else if (sF < 0) bnr(z, R);
    else bnr(L, z);
}


void run() {
    for (int i = 0; i < N - 1; i++) {
        if (i == 1) {
            int dummy = 0;
        }
        isfirstrcsv = true;
        db tempres = bnr(obs[i].x, obs[i + 1].x);
        bdps[i] = tempres;
    }
}


void bpprint() {
    for (int i = 0; i < N - 1; i++) {
        if (i != N - 2) printf("%.10lf ", bdps[i]);
        else printf("%.10lf ", bdps[i]);
    }
    printf("\n");
}


void init() {
    for (int i = 0; i < 10; i++) {
        obs[i].x = 0;
        obs[i].m = 0;
    }
    for (int i = 0; i < 9; i++) {
        bdps[i] = 0;
    }
    N = 0;
    F = 0;
    recentsF = 0;
    isfirstrcsv = false;
}


int main() {
    int TC = 0;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        init();
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &(obs[i].x));
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &(obs[i].m));
        }
        sortobs();
        run();
        printf("#%d ", tc);
        bpprint();
    }
    return 0;
}