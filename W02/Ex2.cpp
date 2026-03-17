#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x;
	cin >> x;
	long double tong = 0;
	double sinx=x;
	int n = 0;
	long long giaithua ;
	while (abs(sinx) >= 0.00001)
	{
		tong += sinx;
		n++;
		giaithua = 1;
		for (int i = 1; i <= (2 * n + 1);i++)
			giaithua *= i;
		sinx = pow(-1, n) * pow(x, 2 * n + 1) /giaithua ;
	}
	cout<<"sin("<<x<<") = "<<fixed<<setprecision(5)<<tong;
	return 0;
}