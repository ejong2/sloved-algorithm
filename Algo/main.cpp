// 백준 13300 방 배정

#include <iostream>

using namespace std;

int main()
{
	int Arr[2][7] = { 0, };

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int S, G;
		cin >> S >> G;

		Arr[S][G]++;
	}

	int Res = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (Arr[i][j] != 0)
			{
				Res += Arr[i][j] / K;

				if (Arr[i][j] % K != 0)
				{
					Res++;
				}
			}
		}
	}

	cout << Res << '\n';

	return 0;
}