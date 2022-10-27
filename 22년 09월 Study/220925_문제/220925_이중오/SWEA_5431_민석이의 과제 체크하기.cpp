#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int n, k;
		cin >> n >> k;

		int used[101] = { 0 };

		for (int i = 0; i < k; i++)
		{
			int ret;
			cin >> ret;
			used[ret] = 1;
		}
		
		cout << "#" << t << " ";

		for (int i = 1; i <= n; i++)
		{
			if (used[i] == 0) cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}