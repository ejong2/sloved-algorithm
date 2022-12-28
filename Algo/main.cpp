// 백준 1748 수 이어 쓰기 1

#include <iostream>

using namespace std;

int main()
{
	int N;
	int cnt = 0;

	cin >> N;

	if (N < 10)
	{
		cout << N << '\n';
		return 0;
	}
	else
	{
		for (int i = 1; i <= N; i *= 10)
		{
			cnt += N - i + 1;
		}
	}
	cout << cnt << '\n';

	return 0;
}