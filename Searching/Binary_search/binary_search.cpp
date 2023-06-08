#include <iostream>
#include <vector>


void binary_search(const std::vector<int>& arr, const int& k)
{

	int low = 0;
	int high = arr.size() - 1;
	bool found = false;
	int index_of_key = -1;

	if ((high == low) && (arr[0] == k))
	{
		found = true;
		index_of_key = 0;
	}

	int mid = (high + low) / 2;

	while ((low <= high) && (!found))
	{

		if (arr[mid] == k)
		{

			found = true;
			index_of_key = mid;

		}
		else
		{ 

			if (k < arr[mid])
				high = mid - 1;
			else 
				low = mid + 1;

			mid = (high + low) / 2;
		}
	}
	std::cout << "Element " << k;

	if (found)
		std::cout << " found at index: " << index_of_key << "." << std::endl;
	else
		std::cout << " not found." << std::endl;

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

	binary_search(darray, key);


	return 0;
}
