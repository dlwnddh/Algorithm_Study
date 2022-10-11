#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define F rcsv(a, b, rcslimit, rcs + 1)
#define X a++; b = b << 1
#define Y a = a << 1; b++
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
	char line2[1000] = { 0, };
	char sline[1000] = { 0, };
	R;
	long long ca = a;
	long long cb = b;
	if (a == b) {
		if (maxN < rcs) maxN = rcs;
		strncpy(sline, path, rcs);
		printf("answer: %20s with value %8lld, N = %4d, [maxN: %d]\n", sline, a, rcs, maxN);

		// sprintf(line2, "%40s %11lld %4d", sline, a, rcs); // (2)
		sprintf(line2, "\"%s\", %lld, %d},", sline, a, rcs);
		fout << line2 << "\n";
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
	fout << "// { {a, b}, \"string\", value, N}" << "\n\n";
	for (long long a = 10; a >= 0; a--) for (long long b = 10; b > a; b--) {
		char line1[100] = { 0, };
		printf("With a = %4lld and b = %4lld ", a, b);
		// sprintf(line1, "%4lld %4lld ", a, b); // (1)
		sprintf(line1, "{ {%d, %d}, ", a, b);
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
	fout << "\n\n\n\n\n\n\n\n[MAX N is " << maxN << "]\n\n\n\n\n";

	return 0;
}