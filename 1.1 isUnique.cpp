#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 
#include <unordered_map>
#include <bitset>
using namespace std;
template<class charT>
bool isUnique(charT const* p)
{
	return isUnique(std::basic_string<charT>(p));
}
template<class charT>
bool isUnique(std::basic_string<charT> s)
{
	if (s.size() <= 1)
	{
		return true;
	}
	unordered_map<charT, bool> charSeen;
	// bool charSeen[256] = { 0 };//256 bytes
	// vector<bool> charSeen(256);//memory efficient
	// bitset<256> charSeen;//memory efficient
	for (int i = 0; i < s.size(); i++)
	{
		if (!charSeen[s[i]])
		{
			charSeen[s[i]] = true;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	cout << isUnique(L"") << endl;
	cout << isUnique(L"test") << endl;
	cout << isUnique("فع") << endl;
	return 0;
}