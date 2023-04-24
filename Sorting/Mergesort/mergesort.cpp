#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& darr, int start, int mid, int end)
{
	vector<int> lh;
	vector<int> hh;

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

void mergesort(vector<int>& darr, int start, int end)
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
	vector<int> darray;
	cout << "Do enter the total count of elements:" << endl;
	cin >> size;

	cout << "Enter the elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> element;
		darray.push_back(element);
	}

	cout << endl;

	mergesort(darray, 0, (darray.size() - 1));

	cout << "Elements after mergesort: " << endl;
	for (auto& vr: darray)
		cout << vr << " ";
	cout << endl;
	return 0;
}
