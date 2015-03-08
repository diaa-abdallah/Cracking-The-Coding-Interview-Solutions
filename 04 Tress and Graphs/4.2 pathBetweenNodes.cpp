#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool pathExists(vector<list<int>>& adjlist, bool visited[], int node1, int node2)
{
	if (node1 == node2)
		return true;
	visited[node1] = true;
	for (int adjacent : adjlist[node1])
	{
		if (!visited[adjacent])
		if (pathExists(adjlist, visited, adjacent, node2))
			return true;
	}
	return false;
}
bool twoNodesPath(vector<list<int>>& adjlist, int node1, int node2)
{
	bool* visited = new bool[adjlist.size()];
	bool n1 = pathExists(adjlist, visited, node1, node2);
	memset(visited, 0, sizeof(bool)* adjlist.size());
	bool n2 = pathExists(adjlist, visited, node2, node1);
	return n1 || n2;
}
int main(int argc, char *argv[])
{
	vector<list<int>> adjlist(5);
	adjlist[0] = { 1, 2 };
	adjlist[1] = { 0 };
	adjlist[3] = { 1 };
	adjlist[4] = { 1 };
	cout << twoNodesPath(adjlist, 2, 0) << endl;
	system("PAUSE");
	return 0;
}