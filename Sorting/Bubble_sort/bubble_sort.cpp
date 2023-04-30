#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& rarray)
{
	int tmp;
	for (int i = 0; i < rarray.size() - 1; i++)
	{
		for (int j = 0; j < rarray.size() - i - 1; j++)
		{
			if (rarray[j] > rarray[j + 1])
			{
				tmp = rarray[j];
				rarray[j] = rarray[j + 1];
				rarray[j + 1] = tmp;
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
	bubble_sort(darray);
	std::cout << "Elements after bubble_sort: " << std::endl;
	for (auto& vr: darray)
		std::cout << vr << " ";
	std::cout << std::endl;
	return 0;
}
