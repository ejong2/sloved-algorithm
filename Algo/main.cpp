// 백준 3986 좋은 단어

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0;

	while (N--)
	{
		string s;
		stack<int> st;

		cin >> s;

		for (auto e : s)
		{
			if (!st.empty() && st.top() == e)
			{
				st.pop();
			}
			else
			{
				st.push(e);
			}
		}
		if (st.empty())
		{
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}