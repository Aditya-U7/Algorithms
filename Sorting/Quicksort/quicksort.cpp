#include <iostream>
#include <vector>

int partition(std::vector<int>& darray, int start, int end)
{
	int pivot = darray[start];
	int high = start;
	int low = start;
	int tmp;

	int pivot_pos = start;

	for (int i = start + 1; i < end; i++)
	{
		if (darray[i] < pivot)
		{
			low = low + 1;

			if (high != start)
			{
				tmp = darray[high];

				darray[high] = darray[i];

				darray[i] = tmp;

				high = low + 1;
			}
		}
		else
		{
			if (high == start)
				high = i;
		}
	}

	tmp = darray[low];
	darray[low] = darray[pivot_pos];
	darray[pivot_pos] = tmp;
	pivot_pos = low;

	return pivot_pos;
}

void quicksort(std::vector<int>& darray, int start, int end)
{
	if ((end - start) < 1)
		return;

	int pivot_pos = partition(darray, start, end);

	quicksort(darray, start, pivot_pos);
	quicksort(darray, pivot_pos + 1, end);

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

	quicksort(darray, 0, darray.size());

	std::cout << "Elements after quicksort: " << std::endl;
	for (auto& vr: darray)
		std::cout << vr << std::endl;
	std::cout << std::endl;
	return 0;
}
