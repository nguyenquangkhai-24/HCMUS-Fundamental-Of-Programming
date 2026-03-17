#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int x)
{
	int can = sqrt(x);
	if (can*can==x)
	{
		return true;
	}
	return false;
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
	cout << "Sum =  ";
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (isPerfectSquare(a[i]))
		{	
			if (i > 0)
			{
				cout << " + ";
			}
			sum += a[i];
			cout << a[i];
		}
	}
	cout << " = " << sum;
	return 0;
}