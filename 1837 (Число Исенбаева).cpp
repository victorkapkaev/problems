#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

bool find(string* arr, string val)
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == val)
			return true;
	}
	return false;
}

int main()
{
	set <string> graph;
	int n;
	string teams[100][3];
	string part;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> teams[i][j];
			graph.insert(teams[i][j]);
		}
	}
	
	set <string> used;
	map <string, int> m;
	m["Isenbaev"] = 0;
	used.insert("Isenbaev");
	queue <string> q;
	q.push("Isenbaev");
	while (!q.empty())
	{
		string current = q.front();
		q.pop();
		int distance = m[current];
		for (int i = 0; i < n; i++)
		{
			if (find(teams[i], current) == true)
			{
				for (int j = 0; j < 3; j++)
				{
					part = teams[i][j];
					if (used.find(part) == used.end())
					{
						used.insert(part);
						q.push(part);
						m[part] = distance + 1;
					}
				}
			}
		}
	}
	for (auto it : graph)
	{
		string name = it;
		cout << name << ' ';
		if (used.find(it) == used.end())
			cout << "undefined" << endl;
		else
			cout << m[name] << endl;
	}
	return 0;
}
