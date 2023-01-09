#include <iostream>
#include <vector>

#define MAX 7

using namespace std;

int Number[MAX];
bool visited[MAX];
vector<int> v[MAX + 1];

void DFS(int x)
{
	if (visited[x])
	{
		return;
	}
	visited[x] = true;

	cout << x << ' ';

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		DFS(y);
	}
}

int main()
{
    v[1].push_back(2);
    v[2].push_back(1);

    v[1].push_back(3);
    v[3].push_back(1);

    v[2].push_back(3);
    v[3].push_back(2);

    v[2].push_back(4);
    v[4].push_back(2);

    v[2].push_back(5);
    v[5].push_back(2);

    v[3].push_back(6);
    v[6].push_back(3);

    v[3].push_back(7);
    v[7].push_back(3);

    DFS(1);  // dfs함수의 시작점을 설정하고 실행


	return 0;
}