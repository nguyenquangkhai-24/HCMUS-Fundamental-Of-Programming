#include <iostream>
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


bool digiteven(int x)
{
	int realnum = x;
	int digit;
	while (realnum > 0)
	{
		digit = realnum % 10;
		realnum /= 10;
		if (digit % 2 == 1)
		{
			return false;
		}
	}
	return true;
}
bool digitodd(int x)
{
	int realnum = x;
	int digit;
	while (realnum > 0)
	{
		digit = realnum % 10;
		realnum /= 10;
		if (digit % 2 == 0)
		{
			return false;
		}
	}
	return true;
}
bool digitmix(int x)
{
	int realnum = x;
	int digit;
	int last=realnum%10;
	realnum /= 10;
	while (realnum > 0)
	{	
		digit = realnum % 10;
		if ((digit%2)==(last%2))
		{
			return false;
		}
		last = digit;
		realnum /= 10;
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
	int k;
	cin >> k;
	cout << "Numbers with " << k << " digits and alternating even/odd: ";
	for (int i = 0; i < n; i++)
	{
		if (digit(a[i]) == k)
		{
			if (digiteven(a[i]) || digitodd(a[i]) || digitmix(a[i]))
			{
				cout << a[i] << ", ";
			}
		}
	}
}