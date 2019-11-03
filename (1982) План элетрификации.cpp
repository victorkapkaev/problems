#include <iostream>

using namespace std;

int power_plant[1000];
bool has_power[1000];
int dist[1000][1000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> power_plant[i];
		has_power[power_plant[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];
	int sum = 0, min_vertex = 1000;
	while (k < n)
	{
		int min = INT_MAX;
		for (int i = 1; i <= n; i++)
		{
			if (!has_power[i])
			{
				for (int j = 0; j < k; j++)
				{
					if (dist[i][power_plant[j]] < min)
					{
						min = dist[i][power_plant[j]];
						min_vertex = i;
					}
				}
			}
		}
		sum += min;
		has_power[min_vertex] = true;
		power_plant[k++] = min_vertex;
	}
	cout << sum;
	return 0;
}
