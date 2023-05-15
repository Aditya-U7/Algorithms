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

int no_of_elements;

std::vector<int> values;

std::cout << "Enter the number of elements: " << std::endl;

std::cin >> no_of_elements;

int element;

std::cout << "Enter the elements:\n";

while (no_of_elements--)
{

std::cin >> element;
values.push_back(element);

}

int max_sum = kadane(values);         // Calling the Kadane's algorithm. It will return the value of the maximum subarray sum.

std::cout << "\nThe largest sum of subarray is: " << max_sum << std::endl;

return 0;
}
