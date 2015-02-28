#include <iostream>
using namespace std;

struct Node{
	int num;
	Node* next;
	Node(int v,Node* n=nullptr):num(v),next(n){}
};
void removeDupes(Node * root)
{
	while(root)
	{
		Node* current=root;
		while(current->next)
		{
			if(current->next->num==root->num)
			{
				Node* temp=current->next;
				current->next=current->next->next;
				delete temp;
			}
			else
			{
				current=current->next;
			}
		}

		root=root->next;
	}
}
void printList(Node * root)
{
	Node* curr=root;
	while(curr)
	{
		cout<<curr->num;
		curr=curr->next;
	}
	cout<<endl;
}
int main() {
	Node* root=new Node(0);
	removeDupes(root);
	printList(root);
	Node* root1=new Node(0,new Node(0));
	removeDupes(root1);
	printList(root1);
	Node* root2=new Node(0,new Node(1,new Node(0)));
	removeDupes(root2);
	printList(root2);
	Node* root3=new Node(0,new Node(1));
	removeDupes(root3);
	printList(root3);
	system("PAUSE");
	return 0;
}
