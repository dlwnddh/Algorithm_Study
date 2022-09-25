#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	for (int t = 1; t <= 10; t++) {
		cin >> T;
		int arr[110][110] = {};
		int ptr = 0;
		int dat[100] = {};
		int sy = -1;
		int sx = -1;
		// arr input
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> arr[y][x];
				if (y == 0 && arr[y][x] == 1) {
					dat[ptr] = x;
					ptr++;
				}
				if (arr[y][x] == 2) {
					sy = y;
					sx = x;
				}
			}
		}
		for (int i = 0; i < ptr; i++) {
			if (dat[i] == sx) ptr = i;
		}
		// last점 기준 위로 올라갈 것
		for (int y = 99; y >= 0; y--) {
			// 오른쪽 1이면
			// 오른쪽 ptr 오른쪽 한칸가고 한칸 올리기
			if (arr[y][dat[ptr] + 1] == 1 && dat[ptr+1] != 0) {
				ptr++;
			}
			// 왼쪽 1이면
			else if (arr[y][dat[ptr] - 1] == 1 && dat[ptr-1]!=0) {
				ptr--;
			}
			// 위로 한 칸 올리기(for문으로 알아서올라감)

		}
		cout << "#"<<T<<" "<<dat[ptr]<<"\n";

	}
	return 0;
}