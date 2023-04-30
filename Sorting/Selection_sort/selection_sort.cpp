#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr)
{
	int tmp;	// temporary variable for holding swap values
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

int main()
{
	int size;
	int element;
	std::vector<int> darray;
	std::cout << "Do enter the total count of elements:" << std::endl;
	std::cin >> size;
	std::cout << "Enter the elements: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> element;
		darray.push_back(element);
	}

	std::cout << std::endl;
	selection_sort(darray);
	std::cout << "Elements after selecton_sort: " << std::endl;
	for (auto& vr: darray)
		std::cout << vr << " ";
	std::cout << std::endl;
	return 0;
}
