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
Uses Queue
*/
void buildList(vector<list<Node*>>& vec, Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	struct node_level{
		Node* n;
		int level;
	};
	queue<node_level> q;
	q.push(node_level{ root, 0 });
	while (!q.empty())
	{
		int currentLevel = q.front().level;
		Node* currentNode = q.front().n;
		if (currentLevel >= vec.size())
		{
			vec.push_back(list<Node*>());
		}
		vec[currentLevel].push_back(currentNode);
		q.pop();
		if (currentNode->left)
		{
			q.push(node_level{ currentNode->left, currentLevel+1 });
		}
		if (currentNode->right)
		{
			q.push(node_level{ currentNode->right, currentLevel + 1 });
		}
	}
}
void buildListOptimized(vector<list<Node*>>& vec, Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	list<Node*> l;
	l.push_back(root);
	vector<list<Node*>> res;
	while (l.size() > 0)
	{
		vec.push_back(l);
		list<Node*> parents = move(l);
		l = list<Node*>();
		for (auto parent : parents)
		{
			if (parent->left)
			{
				l.push_back(parent->left);
			}
			if (parent->right)
			{
				l.push_back(parent->right);
			}
		}

	}
	
}
int main()
{
	Node* root = new Node{ 0, new Node{ 1, new Node{ 3 }, new Node{ 4 } }, new Node{ 2 } };
	vector<list<Node*>> vec;
	buildListOptimized(vec, root);
	return 0;
}