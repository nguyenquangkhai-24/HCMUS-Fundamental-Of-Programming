#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int solonnhat;
	if (a>=b&&a>=c)
	{
		solonnhat = a;
	}
	else if (b>=a&&b>=c)
	{
		solonnhat = b;
	}
	else
	{
		solonnhat = c;
	}
	if (a == b&&b == c)
	{
		cout << "Equilateral triangle";
	}
	else if(a==b||b==c||a==c)
	{
		cout << "Isosceles triangle";
	}
	else if (solonnhat*solonnhat == a*a + b*b + c*c - solonnhat*solonnhat)
	{
		cout << "Right-angled triangle";
	}
	else
	{
		cout << "Scalene triangle";
	}
	return 0;
	
}