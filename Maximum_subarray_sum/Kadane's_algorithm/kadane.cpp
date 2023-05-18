#include <iostream>
#include <vector>
#include <algorithm>


int kadane(std::vector<int>& val)
{

	int max_sum = val[0];
	int curr_sum = 0;

	for (auto& ele : val)
	{

		curr_sum = std::max(curr_sum + ele, ele);
		max_sum = std::max(curr_sum, max_sum);

	}

	return (max_sum);

}


int main()
{

	std::vector<int> values;

	std::cout << "Enter the elements and terminate the input with any character [A to Z]:\n";

	for (int element; std::cin >> element;)
		values.push_back(element);

	if (values.size() == 0)
	{

		std::cout << "Empty array." <<std::endl;
		exit(1);

	}

	int max_sum = kadane(values);         // Calling the Kadane's algorithm. It will return the value of the maximum subarray sum.

	std::cout << "\nThe largest sum of subarray is: " << max_sum << std::endl;

	return 0;
}
