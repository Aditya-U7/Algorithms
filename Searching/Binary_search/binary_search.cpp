#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int>& arr, int& k)
{

	int low = 0;
	int high = arr.size() - 1;
	bool found = false;
	int index_of_key = -1;

	if ((high == low) && (arr[0] == k))
	{
		found = true;
		index_of_key = 0;
	}

	int mid = (high + low) / 2;

	while ((low <= high) && (!found))
	{

		if ( arr[mid] == k)
		{

			found = true;
			index_of_key = mid;

		}
		else
		{ 

			if ( k < arr[mid])
				high = mid - 1;
			else 
				low = mid + 1;

			mid = (high + low) / 2;
		}
	}
	cout << "Element " << k;

	if (found)
		cout << " found at index: " << index_of_key << "." <<endl;
	else
		cout << " not found." <<endl;

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

	binary_search(darray, key);


	return 0;
}
