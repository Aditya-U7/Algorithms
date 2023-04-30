#include <iostream>
#include <vector>


void merge(std::vector<int>& darr, int start, int mid, int end)
{
	std::vector<int> lh;
	std::vector<int> hh;

	for (int i = start; i <= mid; i++)
		lh.push_back(darr[i]);

	for (int i = mid + 1; i <= end; i++)
		hh.push_back(darr[i]);

	int i = 0;
	int j = 0;
	int k = start;

	while ((i < lh.size()) && (j < hh.size()))
	{
		if (lh[i] <= hh[j])
		{
			darr[k] = lh[i];
			i++;
		}
		else if (hh[j] < lh[i])
		{
			darr[k] = hh[j];
			j++;
		}

		k++;
	}

	while (i < lh.size())
	{
		darr[k] = lh[i];
		i++;
		k++;
	}

	while (j < hh.size())
	{
		darr[k] = hh[j];
		j++;
		k++;
	}
}

void mergesort(std::vector<int>& darr, int start, int end)
{
	if ((end - start) < 1)
		return;

	int mid = (start + end) / 2;

	mergesort(darr, start, mid);
	mergesort(darr, mid + 1, end);
	merge(darr, start, mid, end);

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

	mergesort(darray, 0, (darray.size() - 1));

	std::cout << "Elements after mergesort: " << std::endl;
	for (auto& vr: darray)
		std::cout << vr << " ";
	std::cout << std::endl;
	return 0;
}
