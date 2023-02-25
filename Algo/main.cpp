#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;

		int cnt = 0;
		for (int i = a; i <= b; i++)
		{
			string s = to_string(i);

			for (auto e : s)
			{
				if (e == '0') cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}