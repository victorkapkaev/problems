#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

inline int invert(int ch)
{
	return ch == 1 ? 2 : 1;
}

vector<vector<int>> graph(1000);
int colour[1000];

void dfs(int v,int ch)
{
    colour[v] = ch;
	
	for (auto u : graph[v])
	{
		if (colour[u] == 0)
		{
			dfs(u,invert(ch));
		}
		else if (colour[u] == ch) {
			cout << "-1" << endl;
			exit(0);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		while (v != 0)
		{
			graph[i].push_back(v);
			graph[v].push_back(i);
			cin >> v;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (colour[i] == 0)
			dfs(i, 1);
	}
	for (int i = 1; i <= n; i++)
		cout << colour[i]-1;
	return 0;
}
