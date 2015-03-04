#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class MinStack
{
private:
	stack<T> vStack;
	stack<T> mStack;
public:
	void push(T val)
	{
		if (mStack.empty()||val <= mStack.top())
		{
			mStack.push(val);
		}
		vStack.push(val);
	}
	void pop()
	{
		if (mStack.empty())
		{
			throw exception("Empty stack");
		}
		if (vStack.top() == mStack.top())
		{
			mStack.pop();
		}
		vStack.pop();
	}
	T top()
	{
		return vStack.top();
	}
	T min()
	{
		return mStack.top();
	}
	bool empty()
	{
		return vStack.empty();
	}
};
int main(int argc, char *argv[])
{
	MinStack<int> ms;
	ms.push(3);
	ms.push(1);
	ms.push(2);
	cout << ms.top() << endl;
	cout << ms.min() << endl;
	return 0;
}