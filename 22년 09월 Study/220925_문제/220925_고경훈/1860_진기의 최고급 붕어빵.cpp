// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int available(int t, int M, int K) { // available num of product at time x
    int time = t / M;
    return K * time;
}

int main() {
    // data input phase
    int TC = 0;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        bool flagok = true;
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        // N: num of customers
        // M: manufacturing period
        // K: num of product made on one period
        int secs[100];
        for (int i = 0; i < N; i++) scanf("%d", &secs[i]);
        // ******** //

        // calculating phase
        sort(secs, secs + N);
        for (int i = 0; i < N; i++) {
            // we need (i + 1) products at time secs[i]
            if (i + 1 > available(secs[i], M, K)) { // if we don't have enough products
                flagok = false;
                break;
            }
        }
        // ******** //

        // printing phase
        printf("#%d ", tc);

        if (flagok) printf("Possible\n");
        else printf("Impossible\n");
    } // End of for loop (or single testcase)
    return 0;
} // End of main function