#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		int N, Q;
		int arr[1010];
		for (int i = 0; i < 1010; i++)
		{
			arr[i] = 0;
		}
		cin >> N >> Q;
		for (int i = 1; i <= Q; i++)
		{
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++)
			{
				arr[j-1] = i;
			}
		}
		cout << "#" << t + 1 << " ";
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}