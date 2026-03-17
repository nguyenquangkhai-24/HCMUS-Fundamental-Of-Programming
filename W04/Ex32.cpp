#include <iostream>
using namespace std;

bool sotrunglap(int a[], int n, int size)
{	
	int count=0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)
		{
			count++;
		}
	}
	if (count == 1)
	{
		return true;
	}
	if (count > 1)
	{
		return false;
	}
}

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
	for (int i = 0; i < n; i++)
	{
		if (sotrunglap(a, a[i], n))
		{
			b[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		a[i] = b[i];
	}
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << " ";
	}
	return 0;

}