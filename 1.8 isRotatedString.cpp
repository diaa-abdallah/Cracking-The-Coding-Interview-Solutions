#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>

using namespace std;

bool isRotation(const string& s1, const string& s2)
{
	if (s1.size() != s2.size())
	{
		return false;
	}
	string temp = s1 + s1;
	if (temp.find(s2)!=string::npos)
	{
		return true;
	}
	return false;
}
int main(int argc, char *argv[]) 
{
	cout << isRotation("waterbottle", "erbottlewat") << endl;
	return 0;
}