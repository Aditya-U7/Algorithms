#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int lcs(const std::string str1, const std::string str2)
{

	int max_len = 0;

	int row = str1.length();

	int col = str2.length();

	std::vector<int> v((col+1), 0);

	std::vector<std::vector<int>> mat((row+1), v);

	for (int i = (col - 1); i >= 0; --i)
	{

		for (int j = (row - 1); j >= 0; --j)
		{

			if (str1[j] == str2[i])

				mat[j][i] = mat[j+1][i+1] + 1;

			else

				mat[j][i] = std::max(mat[j][i+1], mat[j+1][i]);     

			if (mat[j][i] > max_len)

				max_len = mat[j][i];


		}
	} 

	return(max_len);

}


int main()
{

	std::string str_one;
	std::string str_two;

	std::cout << "\nEnter the first string: " << std::endl;

	std::cin >> str_one;

	std::cout << "\nEnter the second string: " << std::endl;

	std::cin >> str_two;

	lcs(str_one, str_two);

	int maximum_length = lcs(str_one, str_two);

	std::cout << "\nMaximum subsequence is " << maximum_length << std::endl;

	return 0;

}
