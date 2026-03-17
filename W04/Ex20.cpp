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
	int sum = 0;
	cout << "Sum = ";
	if (a[0] > a[1])
	{
		sum += a[0];
		cout << a[0];
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
		    if (i>1)
			{cout << " + ";}
			sum += a[i];
			cout << a[i];
		}
	}
	if (a[n - 1] > a[n - 2])
	{
		sum += a[n - 1];
		cout << " + "<<a[n - 1];
	}
	cout << " = " << sum;
	return 0;
}
