#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &array)
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
	insertion_sort(darray);
	cout << "Elements after insertion_sort: " << endl;
	for (auto &vr: darray)
		cout << vr << endl;
	cout << endl;
	return 0;
}
