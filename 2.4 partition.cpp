#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v,ListNode* n=nullptr):val(v),next(n){}
};

ListNode* partition(ListNode* head,int x)
{
	if(head==nullptr||head->next==nullptr)
	{
		return head;
	}
	
	ListNode* bigger=nullptr;
	ListNode* less=nullptr;
	ListNode* less_head=nullptr;
	ListNode* bigger_head=nullptr;
	while(head)
	{
		if(head->val<x)
		{
			if(less==nullptr)
			{
				less=head;
				less_head=less;
				head=head->next;
				less->next=nullptr;
			}
			else
			{
				less->next=head;
				less=less->next;
				head=head->next;
				less->next=nullptr;
			}
				
			
		}
		else
		{
			if(bigger==nullptr)
			{
				bigger=head;
				head=head->next;
				bigger->next=nullptr;
				bigger_head=bigger;
			}
			else
			{
				bigger->next=head;
				head=head->next;
				bigger=bigger->next;
				bigger->next=nullptr;
			}
		}
	}
	if(less)
	{
		less->next=bigger_head;
		return less_head;
	}
	else
		return bigger_head;
}
int main() {
	ListNode* head=new ListNode(3);
	ListNode* part=partition(head,4);
	system("PAUSE");
	return 0;
}
