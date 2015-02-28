#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v,ListNode* n=nullptr):val(v),next(n){}
};
//recursive
ListNode* aux(ListNode* first,ListNode* second,int carry)
{
	if(first==nullptr&&second==nullptr)
	{
		if (carry>0)
			return new ListNode(carry);
		return nullptr;
	}
	int sum=(carry+ (first?first->val:0 )+ (second?second->val:0) )%10;
	int c=(carry+(first?first->val:0)+(second?second->val:0))/10;
	ListNode* ret=new ListNode(sum);
	ret->next=aux(first?first->next:nullptr,second?second->next:nullptr,c);
	return ret;
}
ListNode* addTwoNumbersRec(ListNode* l1,ListNode* l2) {
	return aux(l1,l2,0);
}

//Iterative
ListNode* addTwoNumbers(ListNode *l1,ListNode* l2)
{
	int carry=0;
	ListNode* sum=nullptr;
	ListNode* current=nullptr;
	while(l1||l2||carry)
	{
		if(current==nullptr)
		{
			current=new ListNode(0);
			sum=current;
		}
		else
		{
			current->next=new ListNode(0);
			current=current->next;
		}
		current->val=((l1?l1->val:0)+(l2?l2->val:0)+carry)%10;
		carry=((l1?l1->val:0)+(l2?l2->val:0)+carry)/10;
		if(l1)
			l1=l1->next;
		if(l2)
			l2=l2->next;
	}
	return sum;
}

int main() {
	ListNode* l1=new ListNode(3);
	ListNode* sum=addTwoNumbers(l1,nullptr);
	system("PAUSE");
	return 0;
}
