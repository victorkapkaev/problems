#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
const double a = 1.41421356237;
double matrix[1002][1002];
double diagonal[1002][1002];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m+1; i++)
		for (int j = 0; j <= n+1; j++)
			matrix[i][j] = 0;
	for (int i = 0; i <= m + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			diagonal[i][j] = 1000;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int u, v;
		cin >> u >> v;
		
		diagonal[v][u] = (100.0 * a);
	}
	for (int i = 0; i <= m+1; i++)
	{
		matrix[i][0] = 100.0 * i;
	}
	for (int i = 0; i <= n+1; i++)
	{
		matrix[0][i] = 100.0* i;
	}
	
	for (int i = 1; i <= m+1; i++)
	{
		for (int j = 1; j <= n+1; j++)
		{
			matrix[i][j] = min(matrix[i-1][j] + 100, min(matrix[i][j-1] + 100, (matrix[i-1][j-1] + diagonal[i][j])));
		}
	}
	cout << round(matrix[m][n]);
	return 0;
}
