#include <iostream>
using namespace std;

long long giaithua(int n)
{
	long long giaithua = 1;
	for (int i = 1; i <= n; i++)
	{
		giaithua *= i;
	}
	return giaithua;
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
	double S = 0;
	for (int k = 1; k <= n; k++)
	{
		S += (double)somu(x, k) / giaithua(k);
	}
	cout << S;
	return 0;
}
