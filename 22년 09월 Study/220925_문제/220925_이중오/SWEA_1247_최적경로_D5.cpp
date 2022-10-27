#include<iostream>
#include<vector>
using namespace std;

int client;
int used[10];
int sum_distance;
int min_root;
int next_distance;

struct Node
{
	int x, y;
};

Node office;
Node home;
Node clients[10];
Node root[12];

void run(int lev)
{
	if (lev == client)
	{
		int sum_distance = 0;

		for (int i = 1; i < client + 2; i++)
		{
			int next_distance = abs(root[i - 1].x - root[i].x) + abs(root[i - 1].y - root[i].y);
			sum_distance += next_distance;
		}

		if (sum_distance < min_root) min_root = sum_distance;
		
		return;
	}

	for (int i = 0; i < client; i++)
	{
		if (used[i] == 1) continue;
		root[lev + 1] = clients[i];
		used[i] = 1;
		run(lev + 1);
		used[i] = 0;
	}

	return;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		min_root = 21e8;

		cin >> client;
		
		for (int i = 0; i < client; i++)
		{
			used[i] = 0;
		}

		cin >> office.x >> office.y;
		root[0] = office;

		cin >> home.x >> home.y;
		root[client + 1] = home;

		for (int i = 0; i < client; i++)
		{
			int x, y;
			cin >> x >> y;
			clients[i] = { x, y };
		}

		run(0);

		cout << "#" << t << " " << min_root << "\n";
	}

	return 0;
}