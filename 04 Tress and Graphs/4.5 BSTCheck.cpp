#include <iostream>
#include <list>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
};
/*
Binary Search Tree defined as:
*The left subtree of a node contains only nodes with keys less than the node's key.
*The right subtree of a node contains only nodes with keys greater than the node's key.
*Both the left and right subtrees must also be binary search trees.
*/
pair<int, int> binarySearchTree(Node* root, bool& bst)
{
	if (root == nullptr)
	{
		return pair<int, int>();
	}
	pair<int, int> maxMinLeft, maxMinRight;
	if (root->left)
	{
		maxMinLeft = binarySearchTree(root->left, bst);
		if (maxMinLeft.second >= root->val)
		{
			bst = false;
		}
	}
	else
	{
		maxMinLeft = make_pair(root->val, root->val);
	}
	if (root->right)
	{
		maxMinRight = binarySearchTree(root->right, bst);
		if (maxMinRight.first <= root->val)
		{
			bst = false;
		}
	}
	else
	{
		maxMinRight = make_pair(root->val, root->val);
	}

	return make_pair(maxMinLeft.first, maxMinRight.second);
}
int main()
{
	Node* root = new Node{ 3, new Node{ 2, new Node{ 1 } }, new Node{ 4 } };
	vector<list<Node*>> vec;
	bool bst = true;
	binarySearchTree(root, bst);
	return 0;
}