#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(int num)
{
    std::string str_num = std::to_string(num);
    std::string reversed_num = str_num;
    std::reverse(reversed_num.begin(), reversed_num.end());
    return str_num == reversed_num;
}

int reverse_number(int num)
{
    std::string str_num = std::to_string(num);
    std::reverse(str_num.begin(), str_num.end());
    return std::stoi(str_num);
}

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        std::cin >> N;
        int reversed_N = reverse_number(N);
        int sum = N + reversed_N;
        if (is_palindrome(sum))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}