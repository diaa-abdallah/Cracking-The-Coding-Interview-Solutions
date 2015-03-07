#include <iostream>
using namespace std;

struct Node{
	int num;
	Node* next;
	Node(int v,Node* n=nullptr):num(v),next(n){}
};
Node* kthToLast(Node* root,int k)
{
	Node* start=root,*end=root;
	while(k>0&&end)
	{
		k--;
		end=end->next;
	}
	if(k!=0)
		return nullptr;
	while(end->next!=nullptr)
	{
		start=start->next;
		end=end->next;
	}
	return start;
}
int main() {
	Node* root=new Node(1,new Node(2));
	Node* kt=kthToLast(root,1);
	if(kt)
		cout<<kt->num<<endl;
	system("PAUSE");
	return 0;
}
