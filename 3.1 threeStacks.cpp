#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>

using namespace std;

template<typename T>
class threeStacks{
private:
	T* _arrayOfStacks;
	size_t stackCapacity[3];
	size_t stackSize[3];
	size_t stackStart[3];

	void growCapacity(unsigned int stackID)
	{
		unsigned int capacitySum = 0;
		size_t newStackCap[3] = { 0, 0, 0 };
		size_t newStackStart[3] = { 0, 0, 0 };
		for (unsigned int i = 0; i < 3; i++)
		{
			if (i == stackID)
			{
				capacitySum += stackCapacity[i] * 2;
				newStackCap[i] = stackCapacity[i] * 2;

			}
			else
			{
				capacitySum += stackCapacity[i];
				newStackCap[i] = stackCapacity[i];
			}
			if (i > 0)
				newStackStart[i] = newStackStart[i - 1] + newStackCap[i - 1];
		}

		T* tempArray = new T[capacitySum];

		for (unsigned int stack_i = 0; stack_i < 3; stack_i++)
		{
			for (unsigned int i = 0; i < stackSize[stack_i]; i++)
			{
				tempArray[newStackStart[stack_i] + i] = _arrayOfStacks[stackStart[stack_i] + i];
			}
		}
		delete[] _arrayOfStacks;
		_arrayOfStacks = tempArray;
		copy(newStackCap, newStackCap + 3, stackCapacity);
		copy(newStackStart, newStackStart + 3, stackStart);
	}
public:
	threeStacks()
	{
		_arrayOfStacks = new T[9];
		fill(stackSize, stackSize + 3, 0);
		fill(stackCapacity, stackCapacity + 3, 3);
		for_each(stackStart, stackStart + 3, [](size_t& val){static int i = 0; val = i; i += 3; });
	}
	void push(unsigned int stackID, T value)
	{
		if (stackID > 2)
		{
			throw invalid_argument("Only 3 stacks Available 0-2");
		}
		if (stackSize[stackID] >= stackCapacity[stackID])
		{
			growCapacity(stackID);
		}
		unsigned int placement = stackStart[stackID] + stackSize[stackID]++;
		_arrayOfStacks[placement] = value;
	}

	T top(unsigned int stackID)
	{
		if (stackSize[stackID] < 1)
		{
			throw invalid_argument("Empty Stack");
		}
		unsigned int place = stackStart[stackID] + (stackSize[stackID] - 1);
		return _arrayOfStacks[place];
	}
	void pop(unsigned int stackID)
	{
		if (stackSize[stackID] == 0)
		{
			throw invalid_argument("Empty Stack");
		}
		--stackSize[stackID];
	}
	bool empty(unsigned int stackID)
	{
		return !stackSize[stackID];
	}
};
int main(int argc, char *argv[])
{
	threeStacks<int> tmp;
	tmp.push(0, 1);
	tmp.push(0, 2);
	tmp.push(0, 3);
	tmp.push(0, 4);
	tmp.push(0, 5);
	tmp.push(1, 6);
	tmp.push(1, 7);
	tmp.push(1, 8);
	cout << tmp.top(0) << endl;
	tmp.pop(0);
	cout << tmp.top(0) << endl;
	cout << tmp.top(1) << endl;
	tmp.pop(1);
	cout << tmp.top(1) << endl;
	return 0;
}