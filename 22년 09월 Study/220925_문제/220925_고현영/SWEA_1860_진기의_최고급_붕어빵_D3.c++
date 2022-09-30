#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[11111];
int main(void)
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		int N, M, K;
		int flag = 0;
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> map[i];
		}
		sort(map, map + N);
		if (map[0] < M)
		{
			cout << "#" << t << " Impossible" << endl;
		}
		else {
			for (int i = 0; i < N; i++) {
				if (K*(map[i] / M) < i + 1)
				{
					flag = -1;
					break;
				}
			}
			if(flag == -1)
				cout << "#" << t << " Impossible" << endl;
			else
				cout << "#" << t << " Possible" << endl;
		}
	}
	return 0;
}