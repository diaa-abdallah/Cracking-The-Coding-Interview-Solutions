#include <iostream>
#include <stack>
#include <string>
using namespace std;
template <typename T>
class Queue{

	stack<T> reversed;
	stack<T> ordered;
public:
	void push(T el)
	{
		/*
		while (!ordered.empty())
		{
			reversed.push(ordered.top());
			ordered.pop();
		}
		*/
		reversed.push(el);
	}
	void pop()
	{
		if (ordered.empty())
		{
			while (!reversed.empty())
			{
				ordered.push(reversed.top());
				reversed.pop();
			}
		}
		ordered.pop();
	}
	T front()
	{
		if (ordered.empty())
		{
			while (!reversed.empty())
			{
				ordered.push(reversed.top());
				reversed.pop();
			}
		}
		return ordered.top();
	}
	bool empty()
	{
		return reversed.empty() && ordered.empty();
	}
};
int main()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.push(4);
	q.pop();
	cout << q.front() << endl;
	q.pop();
	cout << q.front();
	return 0;
}