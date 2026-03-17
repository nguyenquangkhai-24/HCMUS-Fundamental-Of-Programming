#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n;
	int a[1000];
	int temp = 0;
	int b[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	for (int i = n - k; i < n; i++)
	{
		b[temp] = a[i];
		temp++;
	}
	for (int i = 0; i < n - k; i++)
	{
		b[temp] = a[i];
		temp++;
	}
	for (int i = 0; i < temp; i++)
	{
		a[i] = b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	return 0;
}