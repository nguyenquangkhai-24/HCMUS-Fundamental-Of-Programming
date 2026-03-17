#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double tong = 1;
	for (double i = 1; i <= n; i++)
	{
		tong += 1 / (2 * i);
	}
	cout << tong;
	return 0;
}