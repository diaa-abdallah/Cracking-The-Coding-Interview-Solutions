#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>
using namespace std;
string compressString(string s)
{
	if (s.size() < 2)
	{
		return s;
	}
	string compressed;
	int count = 1;
	compressed = s[0];
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1])
		{
			++count;
		}
		else
		{
			compressed += to_string(count);
			compressed += s[i];
			count = 1;
		}
	}
	compressed += to_string(count);
	if (compressed.size() < s.size())
	{
		return compressed;
	}
	else
	{
		return s;
	}
}
int main(int argc, char *argv[]) {

	cout << compressString("") << endl;
	cout << compressString("a") << endl;
	cout << compressString("ab") << endl;
	cout << compressString("abccccc") << endl;
	return 0;
}