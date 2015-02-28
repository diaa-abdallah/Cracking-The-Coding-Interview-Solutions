#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v,ListNode* n=nullptr):val(v),next(n){}
};
ListNode* findLoop(ListNode* head)
{
	unordered_set<ListNode*> set;
	while(head)
	{
		if(set.count(head))
			return head;
		set.insert(head);
		head=head->next;
	}

	return nullptr;
}

int main() {
	ListNode* l1=new ListNode(3,new ListNode(1,new ListNode(4)));
	l1->next->next->next=l1;
	ListNode* point=findLoop(l1);
	system("PAUSE");
	return 0;
}
