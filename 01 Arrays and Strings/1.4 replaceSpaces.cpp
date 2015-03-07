#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>
using namespace std;
void replaceSpaces(char* s,int length)
{
	char* end = s;
	while (*end)
	{
		end++;
	}
	end++;
	char* bufEnd = s + length-1;
	while (end-- != s)
	{
		if (*end == ' ')
		{
			*bufEnd-- = '0';
			*bufEnd-- = '2';
			*bufEnd-- = '%';
		}
		else
		{
			*bufEnd-- = *end;
		}
	}
	
}

int main(int argc, char *argv[]) {
	const int size = 10;
	char s[size] = "  abc";
	replaceSpaces(s, size);
	cout << s << endl;
	return 0;
}