#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>

using namespace std;

void
setToZero(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0)
	{
		return;
	}

	size_t  rows = matrix.size(), cols = matrix[0].size();
	vector<char> rowsZero(rows);
	vector<char> columnsZero(cols);

	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			if (matrix[row][col] == 0)
			{
				rowsZero[row] = 1;
				columnsZero[col] = 1;
			}
		}
	}

	for (size_t row = 0; row < rows; row++)
	{
		if (rowsZero[row] == 1)
		{
			memset(&matrix[row][0], 0, cols*sizeof(int));
		}
	}

	for (size_t col = 0; col < cols; col++)
	{
		if (columnsZero[col] == 1)
		{
			for (size_t row = 0; row < rows; row++)
			{
				matrix[row][col] = 0;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	vector<vector<int>> large = { { 1, 2, 0, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	setToZero(large);
	return 0;
}