#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int demchan = 0;
	int demle = 0;
	int so0 = 0;
	int b[1000];
	int c[1000];
	int d[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			d[so0] = { 0 };
			so0++;
		}
		else if (a[i] % 2 == 0)
		{
			b[demchan] = a[i];
				demchan++;
		}
		else if (a[i] % 2 == 1)
		{
			c[demle] = a[i];
			demle++;
		}
	}
	for (int i = 0; i < demchan; i++)
	{
		a[i] = b[i];
	}
	for (int i = 0; i < so0; i++)
	{
		a[demchan + i] = d[i];
	}
	for (int i = 0; i < demle; i++)
	{
		a[so0+demchan + i] = c[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	return 0;
}