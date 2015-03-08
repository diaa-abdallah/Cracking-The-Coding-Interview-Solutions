#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) :val(v), left(l), right(r){};
};

int balancedAux(TreeNode* n)
{
	if (n == nullptr)
	{
		return 0;
	}
	int l = balancedAux(n->left);
	if (l == -1)
	{
		return -1;
	}
	int r = balancedAux(n->right);
	if (r == -1)
	{
		return -1;
	}
	if (abs(l - r) >= 2)
	{
		return -1;
	}
	else
	{
		return max(l, r) + 1;
	}
}
bool balanced(TreeNode* n)
{
	if (balancedAux(n) == -1)
		return false;
	else
		return true;
}
int main(int argc, char *argv[])
{
	TreeNode* root = new TreeNode{ 1, nullptr, new TreeNode{ 2, nullptr, new TreeNode{ 3 } } };
	cout << balanced(root) << endl;
	system("PAUSE");
	return 0;
}