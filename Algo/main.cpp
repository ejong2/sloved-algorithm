#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int num, int k)
{
	int answer = 0;

	string s = to_string(num);
	string v = to_string(k);

	for (int i = 0; i < s.length(); i++)
	{
		answer = -1;

		if (s[i] == v[0])
		{
			return answer = i + 1;
		}		
	}
	return answer;
}

int main()
{
	cout << solution(29183, 1);

	return 0;
}