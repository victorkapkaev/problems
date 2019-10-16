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

int main()
{
	int n, m;
	vector <int> p1;
	vector <int> p2;
	vector <int> t;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		p1.push_back(l);
		p2.push_back(r);
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		t.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		vector<int>::iterator it1 = find(t.begin(), t.end(), p1[i]);
		vector<int>::iterator it2 = find(t.begin(), t.end(), p2[i]);
		if (it1 >= it2)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
