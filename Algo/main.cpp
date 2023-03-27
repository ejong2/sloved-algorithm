#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		string res = "";

		string s;
		cin >> s;

		for (auto e : s)
		{
			if (isdigit(e))
			{
				res += e;
			}
		}		
		if (stoi(res) <= 90) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}