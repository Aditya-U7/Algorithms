#include <iostream>
#include <vector>


void linear_search(std::vector<int>& arr, int& key)
{

	bool found = false;
	int index_of_element = -1;

	for (auto& v: arr)
	{
		index_of_element++;

		if (v == key)
		{

			found = true;
			break;

		}
	}

	std::cout << "Element " << key <<" ";

	if (found)
		std::cout << "found at index: " << index_of_element << std::endl;
	else
		std::cout << "not found." << std::endl;


}


int main()
{

	std::vector<int> darray;

	int vertices_length;

	int element;

	int key;
	std::cout << "Enter the no of elements: " << std::endl;

	std::cin >> vertices_length;

	std::cout << "Enter the element(s): " << std::endl;
	while (vertices_length--)
	{

		std::cin >> element;
		darray.push_back(element);

	}
	std::cout << "Enter the element to be searched: " << std::endl;
	std::cin >> key;

	linear_search(darray, key);
	return 0;
}
