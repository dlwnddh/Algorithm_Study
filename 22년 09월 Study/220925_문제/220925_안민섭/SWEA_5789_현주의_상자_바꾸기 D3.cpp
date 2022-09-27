#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n, q;
		cin >> n >> q;
		int arr[1100] = {};
		for (int i = 1; i <= q; i++) {
			int l, r;
			cin >> l >> r;
			for (int x = l; x <= r; x++) {
				arr[x] = i;
			}
		}
		cout << "#" << t;
		for (int i = 1; i <= n; i++) {
			cout << " " << arr[i];
		}
		cout << "\n";
	}
	return 0;
}