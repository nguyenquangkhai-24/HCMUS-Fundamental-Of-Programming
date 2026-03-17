#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
	{
		cout << "a cannot equal 0" << endl;
		cin >> a;
	}
	double delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
	{
		cout << "No real roots";
	}
	else if (delta == 0)
	{
		double x = -b / (2.0 * a);
		cout << "One real root: x = " << x;
	}
	else
	{
		double x1 = (-b + sqrt(delta)) / (2.0 * a);
		double x2 = (-b - sqrt(delta)) / (2.0 * a);
		cout << "Two real roots: x1 = " <<fixed<<setprecision(1)<< x1 << ", x2 = " << x2;
	}
	return 0;
}