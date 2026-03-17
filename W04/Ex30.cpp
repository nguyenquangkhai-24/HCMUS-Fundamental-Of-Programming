#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	a[n] = k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n + 1) - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n + 1; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}