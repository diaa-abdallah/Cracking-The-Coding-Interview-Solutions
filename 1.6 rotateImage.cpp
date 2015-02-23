#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix)
{
	int start = 0, cur = 0, n = matrix.size() - 1;
	while (n >= 1)
	{
		for (int cur = 0; cur < n-start; cur++)
		{
			int temp = matrix[start][start + cur];
			matrix[start][start + cur] = matrix[n - cur][start];
			matrix[n - cur][start] = matrix[n][n - cur];
			matrix[n][n - cur] = matrix[start + cur][n];
			matrix[start + cur][n] = temp;
		}
		n --; start++;
	}
}
int main(int argc, char *argv[]) {
	vector<vector<int>> large = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	rotate(large);
	return 0;
}