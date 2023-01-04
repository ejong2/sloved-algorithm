// 백준 11660 구간 합 구하기 5

#include <iostream>

#define MAX 1025

int DP[MAX][MAX];
int MAP[MAX][MAX];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{

			scanf("%d", &MAP[i][j]);
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + MAP[i][j];
		}
	}
	
	int x1, x2, y1, y2;
	int ans;

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);

		ans = DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1];

		printf("%d\n", ans);
	}

	return 0;
}