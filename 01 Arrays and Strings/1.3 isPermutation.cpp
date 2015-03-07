#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
#include <algorithm>
using namespace std;
bool isPermutation(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	if (a == b)
	{
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	cout << isPermutation("abc","bac") << endl;
	return 0;
}