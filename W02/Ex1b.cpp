#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double tong = 0;
	for (double i = 1; i <= n; i++)
	{
		tong += i / (2 * i + 1);
	}
	cout << fixed<<setprecision(9)<<tong;
	return 0;
}