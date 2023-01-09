#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int N, M;
int MAP[MAX][MAX];
int Cnt[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void BFS(int x, int y)
{
	queue<pair<int, int>> q;

	Cnt[x][y]++;
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (MAP[nx][ny] == 1 && !visited[nx][ny])
				{
					Cnt[nx][ny] = Cnt[x][y] + 1;
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}

	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &MAP[i][j]);
		}
	}

	BFS(0, 0);

	cout << Cnt[N - 1][M - 1] << '\n';

	return 0;
}