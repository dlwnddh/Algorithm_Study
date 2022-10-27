#include <iostream>
using namespace std;

int map[100][100];
int dy[3] = { 0, 0, 1 };
int dx[3] = { -1, 1, 0 };

int check_x(int y, int x)
{
	for (int i = 0; i < 2; i++)
	{
		int nx = x + dx[i];

		if (nx < 0 || nx >= 100) continue;

		if (map[y][nx] == 1) return dx[i];
	}

	return 0;
}

int check_down(int y, int x)
{
	int ny = y + dy[2];

	if (map[ny][x] == 1) return dy[2];

	return 0;
}

int move_x(int y, int x, int dir)
{
	while (1)
	{
		x += dir;

		int temp = check_down(y, x);

		if (temp != 0) return x;
	}
}

int down(int y, int x)
{
	while (y < 99)
	{
		int temp = check_x(y, x);

		if (temp != 0) x = move_x(y, x, temp);
		y++;
	}

	if (map[y][x] == 2) return 1;

	return 0;
}

int main()
{

	for (int t = 1; t <= 10; t++)
	{
		int test;
		cin >> test;

		for (int y = 0; y < 100; y++)
		{
			for (int x = 0; x < 100; x++)
			{
				cin >> map[y][x];
			}
		}

		for (int x = 0; x < 100; x++)
		{
			if (map[0][x] == 0) continue;

			int flag = down(0, x);

			if (flag == 1)
			{
				cout << "#" << test << " " << x << "\n";
				break;
			}
		}
	}

	return 0;
}