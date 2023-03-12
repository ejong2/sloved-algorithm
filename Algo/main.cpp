#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (auto e : to_string(i))
		{
			if (e == '3' || e == '6' || e == '9') cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}