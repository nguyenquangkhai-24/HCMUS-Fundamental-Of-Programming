#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	int D = a * e - b * d;
	int Dx = c * e - b * f;
	int Dy = a * f - c * d;
	if (D!=0)
	{
		cout << "Unique solution: x = " << fixed << setprecision(1) << (double)Dx / D << ", y = " << (double)Dy / D;
	}
	else if (D == 0)
	{
		if (Dx == 0 && Dy == 0)
		{
			cout << "Infinitely many solutions";
		}
		else
		{
			cout << "No solution";
		}
	}
	return 0;

}