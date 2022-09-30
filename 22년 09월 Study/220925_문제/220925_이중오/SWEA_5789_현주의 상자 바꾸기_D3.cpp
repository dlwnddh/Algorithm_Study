#include <iostream>
using namespace std;

int nums[1000];

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int n, q;
		cin >> n >> q;

		for (int i = 0; i < n; i++)
		{
			nums[i] = 0;
		}

		for (int i = 1; i <= q; i++)
		{
			int L, R;
			cin >> L >> R;

			for (int j = L - 1; j < R; j++)
			{
				nums[j] = i;
			}
		}

		cout << "#" << t << " ";

		for (int i = 0; i < n; i++)
		{
			cout << nums[i] << " ";
		}

		cout << "\n";
	}

	return 0;
}