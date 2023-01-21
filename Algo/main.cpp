#include <iostream>

using namespace std;

int cnt = 1;
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n * 2 - 1; i++)
	{
		if (i <= n)
		{
			for (int j = n - 1; j >= i; j--)
			{
				cout << " ";
			}

			for (int j = 1; j <= i * 2 - 1; j++)
			{
				cout << "*";
			}
			cout << '\n';
		}
		else
		{
			for (int j = 1; j <= i - n; j++)
			{
				cout << " ";
			}
			for (int j = (n - 1) * 2 - (cnt * 2 - 1); j > 0; j--)
			{
				cout << "*";
			}
			cout << '\n';
			cnt++;
		}
	}

	return 0;
}