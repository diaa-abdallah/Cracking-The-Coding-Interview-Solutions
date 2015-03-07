#include <iostream>
#include<queue>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
struct Animal{
	string name;
	enum animalType{CAT,DOG };
	animalType type;
	time_t time;
};
class CatsAndDogs{
	queue<Animal> cats;
	queue<Animal> dogs;
public:
	void enqueue(Animal a)
	{
		a.time = time(nullptr);
		if (a.type == a.CAT)
		{
			cats.push(a);
		}
		else
		{
			dogs.push(a);
		}
	}
	Animal dequeueAny()
	{
		if (cats.empty() && dogs.empty())
		{
			throw exception("Empty Queue");
		}
		if (dogs.empty()||cats.front().time < dogs.front().time)
		{
			Animal front = cats.front();
			cats.pop();
			return front;
		}
		else
		{
			Animal front = dogs.front();
			dogs.pop();
			return front;
		}
	}
	Animal dequeueDog()
	{
		if (dogs.empty())
		{
			throw exception("Empty Queue");
		}
		Animal front = dogs.front();
		dogs.pop();
		return front;
	}
	Animal dequeueCat()
	{
		if (cats.empty())
		{
			throw exception("Empty Queue");
		}
		Animal front = cats.front();
		cats.pop();
		return front;
	}
};
int main()
{
	CatsAndDogs cd;
	cd.enqueue(Animal{ "Snoopy",Animal::DOG });
	cd.enqueue(Animal{ "Wiskers", Animal::CAT });
	cd.enqueue(Animal{ "Lacy", Animal::DOG });
	cout << cd.dequeueAny().name << endl;
	cout << cd.dequeueDog().name << endl;
	return 0;
}