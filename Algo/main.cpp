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

    sort(v.begin(), v.end()); // 입력된 숫자 배열을 정렬한다.

    int cnt = 0;
    int left = 0, right = N - 1; // 배열의 왼쪽 끝과 오른쪽 끝에서 시작
    while (left < right)
    { // 두 개의 포인터가 만나기 전까지 반복
        int sum = v[left] + v[right];
        if (sum == x)
        { // 두 수의 합이 x와 같은 경우
            cnt++;
            left++; // 왼쪽 포인터를 오른쪽으로 이동하여 다른 조합 찾기
            right--; // 오른쪽 포인터를 왼쪽으로 이동하여 다른 조합 찾기
        }
        else if (sum < x)
        { // 두 수의 합이 x보다 작은 경우
            left++; // 왼쪽 포인터를 오른쪽으로 이동하여 더 큰 수를 선택하도록 한다.
        }
        else
        { // 두 수의 합이 x보다 큰 경우
            right--; // 오른쪽 포인터를 왼쪽으로 이동하여 더 작은 수를 선택하도록 한다.
        }
    }

    cout << cnt << '\n';
    return 0;
}