#include <iostream>
#include <cmath>
using namespace std;

int digit(int x)
{
	int realnum = x;
	int count = 0;
	while (realnum > 0)
	{
		realnum /= 10;
		count++;
	}
	return count;
}

bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <=sqrt(x); i++)
	{
		if (x % i == 0)
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
	cout << "Prime numbers with odd first digit: ";
	for (int i = 0; i < n; i++)
	{
		int firstdigit = a[i] / (int)pow(10, digit(a[i]) - 1);
		if (isPrime(a[i]) && firstdigit % 2 != 0)
		{
			cout << a[i] << " ";
		}
	}
	return 0;

}