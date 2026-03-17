#include <iostream>
#include <cmath>
using namespace std;

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
	for (int i = 1; i <= n; i++)
	{
		s = (double)sqrt(somu(x,i)+s);
	}
	cout << s;
	return 0;
}