#include <iostream>
#include <vector>
using namespace std;


void linear_search(vector<int>& arr, int& key)
{

	bool found = false;
	int index_of_element = -1;

	for (auto& v: arr)
	{
		index_of_element++;

		if (v == key)
		{

			found = true;
			break;

		}
	}

	cout << "Element " << key <<" ";

	if (found)
		cout << "found at index: " << index_of_element << endl;
	else
		cout << "not found." << endl;


}


int main()
{

	vector<int> darray;

	int vertices_length;

	int element;

	int key;
	cout << "Enter the no of elements: " <<endl;

	cin >> vertices_length;

	cout << "Enter the element(s): " <<endl;
	while (vertices_length--)
	{

		cin >> element;
		darray.push_back(element);

	}
	cout << "Enter the element to be searched: " <<endl;
	cin >> key;

	linear_search(darray, key);
	return 0;
}
