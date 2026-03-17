#include <iostream>
using namespace std;

bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++)
	{if (x % i == 0)
		return false;
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
	for (int i = n - 1; i >= 0; i--)
	{
		if(isPrime(a[i]))
		{
			cout << "Last prime: "<<a[i] << " at index " << i << endl;
			break;

		}
	}
}