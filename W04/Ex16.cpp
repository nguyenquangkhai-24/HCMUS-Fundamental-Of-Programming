#include <iostream>
#include <cmath>
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
	cout << "Values: ";
	for (int i = 0; i < n-1; i++)
	{
		if (a[i]>abs(a[i+1]))
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}
