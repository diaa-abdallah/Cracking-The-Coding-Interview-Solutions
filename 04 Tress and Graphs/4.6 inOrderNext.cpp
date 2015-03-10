#include <iostream>
#include <list>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node* parent;
};
Node* leftMostNode(Node* root)
{
	while (root&&root->left)
	{
		root = root->left;
	}
	return root;
}
Node* next(Node* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->right)
	{
		return leftMostNode(root->right);
	}
	auto child = root;
	auto parent = root->parent;
	while (parent&&parent->left != child)
	{
		child = child->parent;
		parent = parent->parent;
	}
	return parent;
}
int main()
{
	Node* r = new Node{ 3};
	r->right = new Node{ 1, nullptr, nullptr, r };
	auto n=next(r->right);
	return 0;
}