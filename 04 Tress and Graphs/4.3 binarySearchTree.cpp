#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode* right;
};
TreeNode* binaryBuilder(int arr[], int start, int end)
{
	if (start == end)
	{
		return new TreeNode{ arr[start] };
	}
	if (start > end)
	{
		return nullptr;
	}
	int mid = start + (end - start) / 2;
	return new TreeNode{ arr[mid], binaryBuilder(arr, start, mid - 1), binaryBuilder(arr, mid + 1, end) };
}
int main(int argc, char *argv[])
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	TreeNode* root = binaryBuilder(arr, 0, 9);
	system("PAUSE");
	return 0;
}