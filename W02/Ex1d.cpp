#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double tong = 0;
	for (double i = 1; i <= n; i++)
	{
		tong += pow(-1, i) * (1 / i);
	}
	cout << tong;
	return 0;
}