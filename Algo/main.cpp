#include <iostream>
#include <algorithm>

using namespace std;

int Arr[6];

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		cin >> Arr[i];
	}

	for (int i = 5; i >= 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				swap(Arr[j], Arr[j + 1]);
				for (int k = 1; k <= 5; k++)
				{
					cout << Arr[k] << " ";
				}
				cout << '\n';
			}
		}
	}

	return 0;
}