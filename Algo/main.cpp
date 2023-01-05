// 소수 찾기 알고리즘

#include <iostream>

using namespace std;

int main()
{
	int N;
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		for (int j = 2; j <= a; j++)
		{
			if (a == j)
			{
				cnt++;
			}
			if (a % j == 0) break;
		}
	}

	cout << cnt << '\n';

	return 0;
}