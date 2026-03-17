#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Local maxima: ";
	if (a[0] > a[1])
	{
		cout << a[0] << " ";
	}
	if (a[n - 1] > a[n - 2])
	{
		cout << a[n - 1] << " ";
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}