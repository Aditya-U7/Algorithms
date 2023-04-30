#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& array)
{
	int tmp;
	for (int i = 1; i < array.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
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
	insertion_sort(darray);
	std::cout << "Elements after Insertion sort: " << std::endl;
	for (auto& vr: darray)
		std::cout << vr << std::endl;
	std::cout << std::endl;
	return 0;
}
