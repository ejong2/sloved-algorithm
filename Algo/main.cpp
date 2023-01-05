#include <iostream>

using namespace std;

int main()
{
	int Number;
	cin >> Number;

	for (int i = 0; i < Number; i++)
	{
		int sum = i;
		int pt = i;

		while (pt)
		{
			sum += pt % 10;
			pt /= 10;
		}    

		if (Number == sum)
		{
			cout << i << '\n';
			return 0;
		}
	}

	cout << "0" << '\n';

	return 0;
}