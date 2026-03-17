#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int b[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int lonnhat = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > lonnhat)
		{
			lonnhat = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	for (int i = 0; i < lonnhat + 1; i++)
	{
		if(b[i]>0)
		{
			cout  << i << ": " << b[i] << " times" << endl;
		}
	}
	return 0;
}