#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, x;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cin >> x;

    sort(v.begin(), v.end()); // �Էµ� ���� �迭�� �����Ѵ�.

    int cnt = 0;
    int left = 0, right = N - 1; // �迭�� ���� ���� ������ ������ ����
    while (left < right)
    { // �� ���� �����Ͱ� ������ ������ �ݺ�
        int sum = v[left] + v[right];
        if (sum == x)
        { // �� ���� ���� x�� ���� ���
            cnt++;
            left++; // ���� �����͸� ���������� �̵��Ͽ� �ٸ� ���� ã��
            right--; // ������ �����͸� �������� �̵��Ͽ� �ٸ� ���� ã��
        }
        else if (sum < x)
        { // �� ���� ���� x���� ���� ���
            left++; // ���� �����͸� ���������� �̵��Ͽ� �� ū ���� �����ϵ��� �Ѵ�.
        }
        else
        { // �� ���� ���� x���� ū ���
            right--; // ������ �����͸� �������� �̵��Ͽ� �� ���� ���� �����ϵ��� �Ѵ�.
        }
    }

    cout << cnt << '\n';
    return 0;
}