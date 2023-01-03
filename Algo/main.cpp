// 백준 2606 바이러스 DFS

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int N, M;
int cnt = 0;
bool visited[MAX];
vector<int> v[MAX];

void DFS(int x)
{
	visited[x] = true;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		if (!visited[y])
		{
			visited[y] = true;
			DFS(y);
			cnt++;
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
	DFS(1);

	cout << cnt << '\n';

	return 0;
}