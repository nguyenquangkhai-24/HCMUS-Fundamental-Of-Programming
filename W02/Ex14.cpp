#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int x = abs(a);
	int y = abs(b);
	int boichungnhonhat;
	int solonhon;
	if (x>y)
		solonhon = x;
	else
		solonhon = y;
	int bcnn = solonhon;
	if (x==0||y==0)
    {
        boichungnhonhat=0;
    }
    else
	{while (b!=0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	while (true)
	{
		if (bcnn % x == 0 && bcnn % y == 0)
		{
			boichungnhonhat = bcnn;
			break;
		}
		bcnn += solonhon;
	}
	}
	cout << "GCD: " << abs(a) << ", LCM: " << boichungnhonhat;
	return 0;
}
