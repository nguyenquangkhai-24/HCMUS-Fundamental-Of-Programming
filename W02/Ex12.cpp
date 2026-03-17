#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x=n;
	int b = n;
	int a[100];
	int count = 0;
	bool palindrome = true;
	while (abs(n) > 0)
	{
		n /= 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		a[i] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		if (a[i] != a[count - i - 1])
		{
			palindrome = false;
			break;
		}

	}
	if (palindrome)
		cout <<b<< " is a palindrome";
	else
		cout <<b<< " is not palindrome";
	return 0;
}
