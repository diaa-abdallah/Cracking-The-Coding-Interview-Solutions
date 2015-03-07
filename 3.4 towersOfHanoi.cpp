#include <iostream>
#include <stack>
#include <string>
template <class T>
class stack :public std::stack<T>{
	
public:
	std::string name;
	stack(std::string name){
		this->name = name;
	}
};

template<typename T>
void moveDisks(int n, stack<T>& origin, stack<T>& destination, stack<T> &buffer)
{
	if (n == 0 || origin.empty())
	{
		return;
	}
	moveDisks(n - 1, origin, buffer, destination);
	destination.push(origin.top());
	printf("Transfered %d from %c to %c\n", origin.top(),origin.name[0],destination.name[0]);
	origin.pop();
	moveDisks(n - 1, buffer, destination, origin);
}
int main()
{
	stack<int> A("A"), B("B"), C("C");
	A.push(3);
	A.push(2);
	A.push(1);
	moveDisks(3, A, C,B);
	return 0;
}