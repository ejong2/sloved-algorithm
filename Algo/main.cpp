#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s1, s2;
	while (n--)
	{
		cin >> s1 >> s2;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1 == s2)
		{
			cout << "Possible" << '\n';
		}
		else
		{
			cout << "Impossible" << '\n';
		}
	}

	return 0;
}