#include <iostream>
#include <cmath>
using namespace std;

long long giaithua(int n)
{
	if (n == 0) return 1;
	long long giaithua = 1;
	for (int i = 1; i <= n; i++)
	{
		giaithua *= i;
	}
	return giaithua;
}
int main()
{
	int n;
	cin >> n;
	double s = 0;
	for (int i = 1; i <= n ; i++)
	{
		s = (double)(pow(giaithua(i)+s, 1.0 / (i+1)));
	}
	cout << s;
	return 0;
}
