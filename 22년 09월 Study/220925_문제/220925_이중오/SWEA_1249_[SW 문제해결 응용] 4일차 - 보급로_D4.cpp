#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Node
{
	int y, x;
	int price;
};

bool operator<(Node v, Node t)
{
	return t.price < v.price;
}

int result[100][100];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int n;
		cin >> n;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				result[y][x] = 1000;
			}
		}

		vector<string> map;

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			map.push_back(str);
		}

		priority_queue<Node> pq;
		pq.push({ 0, 0, 0 });
		result[0][0] = map[0][0] - '0';

		while (!pq.empty())
		{
			Node now = pq.top();
			pq.pop();

			if (now.price > result[now.y][now.x]) continue;
			
			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

				int next_price = map[ny][nx] - '0';
				int next_result = next_price + now.price;

				if (next_result >= result[ny][nx]) continue;

				result[ny][nx] = next_result;
				pq.push({ ny, nx, result[ny][nx] });
			}
		}

		cout << "#" << t << " " << result[n - 1][n - 1] << "\n";
	}

	return 0;
}