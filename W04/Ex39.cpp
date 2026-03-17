#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int b[1000];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int lonnhat = a[0];
	int vitrilonnhat = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > lonnhat)
		{
			lonnhat = a[i];
			vitrilonnhat = i;
		}
	}
	cout << "Longest value = " << lonnhat;
	for (int i = 0; i <= vitrilonnhat; i++)
	{
		if (a[i] < a[i + 1])
		{
			b[count] = a[i];
			count++;
		}
	}
	b[count] = lonnhat;
	cout << "Longest increasing subarrays: ";
	for (int i = 0; i < count+1; i++)
		cout << b[i]<<" ";
	return 0;
}
