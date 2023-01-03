// 백준 2606 바이러스 BFS

#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int N, M;
int cnt = 0;
bool visited[MAX];
queue<int> q;
vector<int> v[MAX];

void BFS(int x)
{
	visited[x] = true;
	q.push(x);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!visited[y])
			{
				visited[y] = true;
				q.push(y);
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS(1);

	cout << cnt << '\n';

	return 0;
}