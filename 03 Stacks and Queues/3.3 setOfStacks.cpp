#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<class T>
class SetOfStacks{
	vector<stack<T>> _stacks;
	const unsigned int _maxStackSize;
public:
	SetOfStacks(unsigned int maxStackSize) :_maxStackSize(maxStackSize)
	{
		_stacks.push_back(stack<T>());
	}
	void push(T val)
	{
		if (_stacks.back().size() < _maxStackSize)
		{
			_stacks.back().push(val);
		}
		else
		{
			_stacks.push_back(stack<T>());
			_stacks.back().push(val);
		}
	}
	T top()
	{
		if (_stacks.empty())
		{
			throw exception("Empty Stack");
		}
		return _stacks.back().top();
	}
	void pop()
	{
		if (_stacks.empty())
		{
			throw exception("Empty Stack");
		}
		_stacks.back().pop();
		if (_stacks.back().empty())
		{
			_stacks.pop_back();
		}
	}
	
	/*
	Removes element at the specified stack.
	O(n) time since it does a rollover to keep all stacks at capacity.
	*/
	void popAt(unsigned int index)
	{
		if (index >= _stacks.size())
		{
			throw out_of_range("Index Out of Bounds");
		}
		_stacks[index].pop();
		while (index+1 < _stacks.size())
		{
			_stacks[index].push(_stacks[index + 1].top());
			_stacks[index + 1].pop();
			++index;
		}
		if (_stacks[index].empty())
		{
			_stacks.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
	SetOfStacks<int> so(3);
	so.push(1);
	so.push(2);
	so.push(3);
	so.push(4);
	cout << so.top() << endl;
	so.popAt(1);
	so.popAt(1);
	return 0;
}