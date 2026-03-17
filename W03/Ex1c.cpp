#include <iostream>
using namespace std;

int tong(int n)
{
	int tong = 0;
	for (int i = 1; i <= n; i++)
	{
		tong += i;
	}
	return tong;
}
int somu(int a, int b)
{
	int somu = 1;
	for (int i = 1; i <= b; i++)
	{
		somu *= a;
	}
	return somu;
}
int main()
{
	int n, x;
	cin >> n >> x;
	double s = 0;
	for (int k = 1; k <= n; k++)
	{
		s += (double)somu(x, k) / tong(k);
	}
	cout << s;
	return 0;
}