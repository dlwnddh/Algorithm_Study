#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int n, m, k;
		cin >> n >> m >> k;	// m : 시간, k : 붕어빵 수

		int used[11112] = { 0 };
		int fish = 0;
		int people = 0;

		for (int i = 0; i < n; i++)
		{
			int ret;
			cin >> ret;
			used[ret]++;
		}

		int flag = 0;

		for (int i = 0; i < 11112; i++)
		{
			if (i != 0 && i % m == 0) fish += k;
			if (used[i] != 0) people += used[i];

			if (people > fish) flag = 1;
			if (fish == n) break;
		}

		if (flag == 0) cout << "#" << t << " Possible\n";
		else cout << "#" << t << " Impossible\n";
	}

	return 0;
}