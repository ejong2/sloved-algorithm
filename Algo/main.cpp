// 백준 11441 합 구하기

#include <iostream>

#define MAX 100001

using namespace std;

int Arr[MAX];

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a;
		scanf_s("%d", &a);

		Arr[i + 1] = Arr[i] + a;
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int b, c;
		scanf_s("%d", &b);
		scanf_s("%d", &c);

		printf("%d\n", Arr[c] - Arr[b - 1]);
	}

	return 0;
}