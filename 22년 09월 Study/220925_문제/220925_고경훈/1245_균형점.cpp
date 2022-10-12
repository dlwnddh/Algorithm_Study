// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define delta 0.000000000001 // 1E-12
#define sdelt 0.000000000000001 // 1E-15
struct object {
    int x;
    int m;
};
using namespace std;


int N;
double F;
object obs[10];
double balancedpoints[9];
double recentsF;
bool isfirstrcsv = false;


double force(double x, int n) { // objectnumber n
    // <- direction force is (-)
    // -> direction force indicated by (+)

    double amount = obs[n].m / ((x - obs[n].x) * (x - obs[n].x));
    if (obs[n].x < x) return (-1) * amount;
    else return amount;
}


double netforce(double x) {
    double netforce = 0;
    for (int i = 0; i < N; i++) {
        netforce += force(x, i);
    }
    return netforce;
}


void sortobs() {
    struct fuck_yeah {
        bool operator()(object a, object b) {
            return a.x > b.x;
        }
    };
    priority_queue<object, vector<object>, fuck_yeah> pq;
    for (int i = 0; i < N; i++) {
        pq.push(obs[i]);
    }
    for (int i = 0; i < N; i++) {
        object temp = pq.top();
        obs[i] = temp;
        pq.pop();
    }
}


double dobinary(double L, double R) {
    double RL = R - L;
    double z = (L + R) / 2;
    double sF = netforce(z);
    double dif_now_before = sF - recentsF;
    if (
        !isfirstrcsv &&
        (-1) * sdelt < dif_now_before &&
        dif_now_before < sdelt
        ) {
        return z;
    }
    recentsF = sF;
    isfirstrcsv = false;
    if (RL < delta) return z;
    else if (sF < 0) dobinary(z, R);
    else dobinary(L, z);
}


void run() {
    for (int i = 0; i < N - 1; i++) {
        if (i == 1) {
            int dummy = 0;
        }
        isfirstrcsv = true;
        double tempres = dobinary(obs[i].x, obs[i + 1].x);
        balancedpoints[i] = tempres;
    }
}


void bpprint() {
    for (int i = 0; i < N - 1; i++) {
        if (i != N - 2) printf("%.10lf ", balancedpoints[i]);
        else printf("%.10lf ", balancedpoints[i]);
    }
    printf("\n");
}


void init() {
    for (int i = 0; i < 10; i++) {
        obs[i].x = 0;
        obs[i].m = 0;
    }
    for (int i = 0; i < 9; i++) {
        balancedpoints[i] = 0;
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

    } // End of single testcase



    return 0;
}