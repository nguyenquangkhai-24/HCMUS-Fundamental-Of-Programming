#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
			break;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int b[1000];
	int c[1000];
	int prime = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (isPrime(a[i]))
		{
			b[prime] = a[i];
			c[prime] = i;
			prime+=1;
		}
	}
	cout << "Prime: ";
	for (int i = 0; i < prime; i++)
	{	
		cout << b[i] << " ";
	}
	cout << "-> reversed to ";
	for (int i = 0; i < prime / 2; i++)
	{
		int temp = b[i];
		b[i] = b[prime - i - 1];
		b[prime - i - 1] = temp;
	}
	for (int i = 0; i < prime / 2; i++)
	{
		int temp = a[c[i]];
		a[c[i]] = a[c[prime - i - 1]];
		a[c[prime-i-1]]=temp;
	}
	for (int i = 0; i < prime; i++)
	{
		cout << b[i] << " ";
	}
	cout << "Result: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	return 0;
}