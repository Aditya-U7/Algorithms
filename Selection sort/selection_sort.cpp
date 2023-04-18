#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr)
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
	selection_sort(darray);
	cout << "Elements after selecton_sort: " << endl;
	for (auto &vr: darray)
		cout << vr << " ";
	cout << endl;
	return 0;
}
