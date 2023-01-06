// 문자열 뒤집기 함수

#include <iostream>

#define MAX 101

using namespace std;

void ReverseString(char* str)
{
	int n = strlen(str);

	for (int i = 0; i < n / 2; i++)
	{
		int tmp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = tmp;
	}
	cout << str;
}

int main()
{
	char c[MAX];
	cin >> c;

	ReverseString(c);

	return 0;
}