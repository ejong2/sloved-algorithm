// 백준 9093 단어 뒤집기

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();

	stack<char> st;

	while (T--)
	{
		string str;
		getline(cin, str);
		str += ' ';

		for (auto e : str)
		{
			if (e == ' ')
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
				cout << e;
			}
			else
			{
				st.push(e);
			}
		}
		cout << '\n';
	}

	return 0;
}