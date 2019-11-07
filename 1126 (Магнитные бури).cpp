#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int max_v(vector<int> arr, int l, int r)
{
	int max = -1;
	for (int i = l; i <= r; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main()
{
	int m,x;
	cin >> m;
	cin >> x;
	while (x != -1)
	{
		arr.push_back(x);
		cin >> x;
	}
	for (int i = 0; i <= arr.size()-m; i++)
	{
		cout << max_v(arr,i, i + m - 1) << endl;
	}
	return 0;
}
