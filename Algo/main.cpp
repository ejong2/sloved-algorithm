// ���� 1436 ��ȭ���� ��

#include <iostream>

using namespace std;

int main()
{
	int start = 666, cnt = 0, tmp;
	int N;
	cin >> N;

	while (1)
	{
		tmp = start;
		do
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			tmp /= 10;

		} while (tmp > 0);

		if (cnt == N)
		{
			cout << start << '\n';
			break;
		}
		start++;
	}

	return 0;
}