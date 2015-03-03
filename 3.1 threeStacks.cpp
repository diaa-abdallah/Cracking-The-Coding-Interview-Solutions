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
	size_t stackCapacity[3] = { 3, 3, 3 };
	size_t stackSize[3] = { 0, 0, 0 };

	void growCapacity(unsigned int stackID)
	{
		unsigned int capacitySum = 0;
		size_t newStackCap[3] = { 0, 0, 0 }
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
		}

		T* tempArray = new T[capacitySum];

		for (unsigned int i = 0; i < capacitySum; i++)
		{


		}
	}
public:
	threeStacks()
	{
		_arrayOfStacks = new T[9];
	}
	void push(unsigned int stackID, T value)
	{
		if (stackID > 2)
			throw invalid_argument("Only 3 stacks Available 0-2");
		if (stackSize[stackID] > stackCapacity[stackID])
			growCapacity(stackID);
	}

	T top(unsigned int stackID)
	{

	}
	void pop(unsigned int stackID)
	{

	}
};
int main(int argc, char *argv[])
{
	threeStacks<int> tmp;
	tmp.push(1);

	return 0;
}