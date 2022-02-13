#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int noOfOnes = 0, max = 0, current = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;

		if (temp == 1)
		{
			current > 0 && --current;
			++noOfOnes;
		}
		else
			++current;

		if (current > max)
			max = current;
	}

	if (max == 0)
		max = -1;

	std::cout << noOfOnes + max << "\n";
	return 0;
}

/*
1 1 0 0 0 1 0 0 1 0 1 1 1 1 0
*/