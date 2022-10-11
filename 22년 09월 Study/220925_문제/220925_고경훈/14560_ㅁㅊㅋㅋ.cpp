#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define F rcsv(a, b, rcslimit, rcs + 1)
#define X a++; b *= 2
#define Y a *= 2; b++
#define P // printf("a = %lld, b = %lld\n", a, b)
#define N // printf("with n = %d\n", n);
#define R if(endflag) return
#define A 7
#define B 31
#define D long long a = A; long long b = B
using namespace std;

char path[1000] = { 0, };
bool endflag = false;
int maxN = -1;

ofstream fout;

void rcsv(long long a, long long b, int rcslimit, int rcs) {
	char line[1000] = { 0, };
	char sline[1000] = { 0, };
	R;
	long long ca = a;
	long long cb = b;
	if (a == b) {
		if (maxN < rcs) maxN = rcs;
		strncpy(sline, path, rcs);
		printf("answer: %20s with value %8lld, N = %4d, [maxN: %d]\n", sline, a, rcs, maxN);
		sprintf(line, "%40s %11lld %4d", sline, a, rcs);

		fout << line << "\n";
		endflag = true;
		return;
	}
	if (rcs >= rcslimit) return;
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			path[rcs] = 'X';
			X;
			P;
			F;
			R;
			path[rcs] = 0;
		}
		a = ca;
		b = cb;
		if (i == 1) {
			path[rcs] = 'Y';
			Y;
			P;
			F;
			R;
			path[rcs] = 0;
		}
	}
}


int main() {
	D;

	fout.open("resu.txt");
	for (long long a = 0; a <= 100; a++) for (long long b = a; b <= 100; b++) {
		char line1[100] = { 0, };
		printf("With a = %4lld and b = %4lld ", a, b);
		sprintf(line1, "%4lld %4lld ", a, b);
		fout << line1;
		int n = 1;
		while (1) {
			endflag = false;
			N;
			rcsv(a, b, n, 0);
			// R 0;
			if (endflag) break;
			n++;
		}
	}
	printf("\n\n\n\n\n\n\n\n[MAX N is %d]\n\n\n\n\n", maxN);

	return 0;
}