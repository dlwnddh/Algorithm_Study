#define _CRT_SECURE_NO_WARNINGS
#define MX 1001
#include <stdio.h>

int TC;
typedef struct sexonthebeach {
    int left;
    int right;
} LR;


void printbox(int boxes[], int N) {
    for (int i = 1; i <= N; i++) {
        if (i == N) printf("%d", boxes[i]);
        else printf("%d ", boxes[i]);
    }
}


void run(int N, int Q, LR works[], int used[], int boxes[]) {
    for (int q = Q; q >= 1; q--) {
        int L = works[q].left;
        int R = works[q].right;
        for (int idx = L; idx <= R; idx++) {
            if (used[idx]) continue;
            used[idx] = 1;
            boxes[idx] = q;
        }
    }
    printbox(boxes, N);
    printf("\n");
}


void getinput_single_testcase(int* N, int* Q, LR works[]) {
    scanf("%d %d", N, Q);
    for (int i = 1; i <= *Q; i++) {
        scanf("%d %d", &(works[i].left), &(works[i].right));
    }
}


int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        int N = 0; // Num of boxes
        int Q = 0; // Num of works
        int boxes[MX] = { 0, };
        LR works[MX] = { {0, 0}, };
        int used[MX] = { 0, };
        getinput_single_testcase(&N, &Q, works);

        printf("#%d ", tc);
        run(N, Q, works, used, boxes);
    }
}