#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dat[100];
int main(void)
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		int N, K;
		cin >> N >> K;
		int arr[100];
		for (int i = 0; i < N+1; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < K; i++)
		{
			int a;
			cin >> a;
			arr[a] = 1;
		}
		cout << "#" << t + 1 << " ";
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] == 0)
				cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}