#include <iostream>
using namespace std;

bool isPalindromic(int x)
{
	int count = 0;
	int realnumber = x;
	int b[100];
	if (x < 10)
	{
		return false;
	}
	while (realnumber != 0)
	{
		b[count] = realnumber % 10;
		realnumber /= 10;
		count++;
	}
	for (int i = 0; i < count / 2; i++)
	{
		if (b[i] != b[count - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int tich = 1;
	for (int i = 0; i < n; i++)
	{
		if (isPalindromic(a[i]))
		{	
			if (i>0)
			{
				cout << " * ";
			}
			tich *= a[i];
			cout << a[i];
		}
	}
	cout << " = " << tich;
}