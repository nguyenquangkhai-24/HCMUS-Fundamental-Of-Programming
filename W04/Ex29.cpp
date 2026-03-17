#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n>>k;
	int a[1000];
	int b[1000];
	int c[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
	}
	for (int i=0;i<n;i++)
	{
		c[i]=a[i];
	}
	for (int i = 0; i < k; i++)
	{
		c[i+n] = b[i];
	}
	for (int i = 0; i < (n + k-1); i++)
	{
		for (int j = 0; j < (n + k - 1 - i); j++)
		{
			if (c[j] > c[j+1])
			{
				int temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < n + k; i++)
	{	
		cout << c[i]<<" ";
	}
	return 0;

}