// น้มุ 15649 Nฐ๚ M (1)

#include <iostream>

#define MAX 9

using namespace std;

int N, M;
int Arr[MAX];
bool visited[MAX];

void DFS(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			Arr[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	DFS(0);

	return 0;
}