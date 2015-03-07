#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v,ListNode* n=nullptr):val(v),next(n){}
};
bool palindrome(ListNode* head)
{
	stack<int> st;
	ListNode* current=head;
	while(current)
	{
		st.push(current->val);
		current=current->next;
	}
	while(!st.empty())
	{
		if(st.top()!=head->val)
			return false;
		head=head->next;
		st.pop();
	}
	return true;
}

int main() {
	ListNode* l1=new ListNode(3,new ListNode(1,new ListNode(3)));
	cout<<palindrome(l1)<<endl;
	system("PAUSE");
	return 0;
}
