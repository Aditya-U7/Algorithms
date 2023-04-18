#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &rarray)
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
	bubble_sort(darray);
	cout << "Elements after bubble_sort: " << endl;
	for (auto &vr: darray)
		cout << vr << " ";
	cout << endl;
	return 0;
}

