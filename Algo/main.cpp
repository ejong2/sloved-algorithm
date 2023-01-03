// 백준 11659 구간 합 구하기 4

#include <iostream>

using namespace std;

long long Arr[100001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		Arr[i + 1] = Arr[i] + a;
	}
	for (int i = 0; i < M; i++)
	{
		int b, c;
		cin >> b >> c;

		cout << Arr[c] - Arr[b - 1] << '\n';
	}

	return 0;
}