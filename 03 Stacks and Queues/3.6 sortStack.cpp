#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
void sortStack(stack<int>& st)
{
	stack<int> temp;
	int current = 0;
	int size = st.size();
	while (current < st.size())
	{
		int min = INT_MAX;
		while (st.size() > current)
		{
			min = std::min(st.top(), min);
			temp.push(st.top());
			st.pop();
		}
		st.push(min);
		while (!temp.empty())
		{
			if (temp.top() != min)
			{
				st.push(temp.top());
				
			}
			temp.pop();
		}
		current++;

	}
}

int main()
{
	stack<int> q;
	q.push(1);
	q.push(5);
	q.push(3);
	q.push(9);
	sortStack(q);
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	
	q.pop();
	cout << q.top() << endl;
	q.pop();
	cout << q.top();
	return 0;
}