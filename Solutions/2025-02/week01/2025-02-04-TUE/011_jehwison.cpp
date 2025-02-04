#include<vector>
#include<iostream>
#include <algorithm>

int main(void)
{
	int vectorSize = 0;
	std::vector<int> vec;

	std::cin >> vectorSize;

	for (int i = 0; i < vectorSize; i++)
	{
		int input = 0;
		std::cin >> input;
		vec.push_back(input);
	}

    sort(vec.begin(), vec.end());

	for (int i = 0; i < vectorSize; i++)
	{
		std::cout << vec[i] << " ";
	}

	return 0;
}
