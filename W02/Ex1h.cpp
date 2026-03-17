#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int tong = 0;
	int giaithua = 1;
	double s = 0;
	for (int i = 1; i <= n; i++) {
		tong += i;
		giaithua *= i;
		s += (double)tong / giaithua;
	}
	cout << s;
	return 0;
}