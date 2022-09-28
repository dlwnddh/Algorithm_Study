#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node {
	int y, x;
};
int n;
int mini;
Node arr[13] = {};
int used[13] = {};
void run(int lev, int sum, int index) {
	if (lev == n ) {
		// sum + 원점까지 거리 해서 최솟값 기록
		sum += (abs(arr[index].y - arr[1].y) + abs(arr[index].x - arr[1].x));
		mini = min(mini, sum);
		return;
	}
	for (int i = 2; i < n + 2; i++) {
		if (used[i]) continue;
		used[i] = 1;
		int a = (abs(arr[index].y - arr[i].y) + abs(arr[index].x - arr[i].x));
		run(lev + 1, sum + a, i);
		used[i] = 0;
	}
}
void init() {
	for (int i = 0; i < 13; i++) {
		used[i] = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		mini = 21e8;
		init();
		for (int i = 0; i < n + 2; i++) {
			cin >> arr[i].y >> arr[i].x;
		}
		used[0] = 1;
		run(0,0,0);
		cout << "#" << t << " " << mini << "\n";

	}
	return 0;
}