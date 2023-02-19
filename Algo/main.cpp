#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cout << "=";
		}
		cout << '\n';
	}

	return 0;
}