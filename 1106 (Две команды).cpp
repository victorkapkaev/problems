#pragma comment(linker, "/STACK:128777216")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <fstream>
#include <iomanip>

using namespace std;

vector<vector<int>> graph(1000);
bool used[1000];
char colour [1000];

inline char invert(int c) {
	return c == 1 ? 2 : 1;
}

void dfs(int vertex, char c)
{
	/*cout << "We at #" << vertex << " " << (bool)colour << endl;*/
	colour[vertex] = c;
	used[vertex] = true;
	for (auto child : graph[vertex])
	{
		if (!used[child])
			dfs(child, invert(c));
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int u;
		cin >> u;
		while (u != 0)
		{
			graph[i].push_back(u);
			graph[u].push_back(i);
			cin >> u;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
			dfs(i, 1);
	}
	int counter = 0;
	for (int i = 1; i <= n; i++)
	{
		if (colour[i] == 2)
			counter++;
	}
	cout << counter << endl;
	for (int i = 1; i <= n; i++)
	{
		if (colour[i] == 2)
			cout << i << " ";
	}
	return 0;
}
