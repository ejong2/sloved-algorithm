#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> v)
{
    if (v[0] < v[1])
        swap(v[0], v[1]);
    return v[1] * 2 - 1;
}


int main()
{
    string s = "aAb1B2cC34oOp";

    cout << solution();

    return 0;
}