#include <iostream>
#include <queue>
#include <vector>

#define MAX 7

using namespace std;

int number[MAX];
bool visited[MAX];
vector<int> v[8];

void BFS(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;
	
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << ' ';
		
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
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

	BFS(1);

	return 0;
}