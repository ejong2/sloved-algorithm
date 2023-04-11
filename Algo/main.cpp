#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int nums[45];
	srand(time(NULL));

	for (int i = 0; i < 45; i++)
	{
		nums[i] = i + 1;
	}

	for (int i = 0; i < 45; i++)
	{
		int j = rand() % 45;
		swap(nums[i], nums[j]);
	}
	sort(nums, nums + 6);
	for (int i = 0; i < 6; i++)
	{
		cout << nums[i] << " ";
	}
	cout << '\n'; 

	return 0;
}