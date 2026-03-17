#include <iostream>
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
	cout << "Pairs: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i]<a[j])
			{
				cout << "(" << a[i] << "," << a[j] << ")," << " ";
			}
		}
	}
	return 0;
}
