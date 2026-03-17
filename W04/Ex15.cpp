#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Closet pair: ";
	double nhonhat = abs(a[0] - a[1]);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) < nhonhat)
			{
				nhonhat = abs(a[i] - a[j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) == nhonhat)
			{
				cout << "(" << a[i] << "," << a[j] << ")" << " ";
			}
		}
	}

	return 0;
}