#include <iostream>
using namespace std;

struct Node{
	int num;
	Node* next;
	Node(int v,Node* n=nullptr):num(v),next(n){}
};
/*
Deletes a node given only access to it
Special Cases:
If the node is the last node, it is deleted and the reference is set to null
If the node is null an exception is thrown
O(1) complexity
*/
void deleteNode(Node*& n)
{
	if(n==nullptr)
	{
		throw invalid_argument("n is null");
	}
	if(n->next==nullptr)
	{
		delete n;
		n=nullptr;
		return;
	}
	n->num=n->next->num;
	Node* temp=n->next;
	n->next=n->next->next;
	delete temp;
}
int main() {
	Node* root=new Node(1,new Node(2));
	Node* toDelete=root->next;
	deleteNode(toDelete);
	system("PAUSE");
	return 0;
}
