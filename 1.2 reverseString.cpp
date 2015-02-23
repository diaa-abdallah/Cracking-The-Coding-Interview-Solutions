#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
using namespace std;
void reverseString(char* s)
{
	int len = strlen(s);
	char* start = s, *end = s + len - 1;
	while (start < end)
	{
		swap(*start++, *end--);
	}
}

int main(int argc, char *argv[]) {
	char s[] = "This is a test";
	reverseString(s);
	cout << s << endl;
	return 0;
}