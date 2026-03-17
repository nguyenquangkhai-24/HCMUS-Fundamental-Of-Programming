#include <iostream>
using namespace std;

bool chuatimthay(int a[], int n, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)
			return false;
	}
	return true;
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
		if (chuatimthay(b, a[i], count))
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
		cout << a[i]<<" ";
	}
	return 0;
	
}