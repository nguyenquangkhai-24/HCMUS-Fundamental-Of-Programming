#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double tong = 0;
	for (int i = 1; i <= n; i++)
	{
		tong += pow(i, i);
	}
	cout << tong;
	return 0;
}
