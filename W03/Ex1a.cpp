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
int main()
{
	int n, k;
	cin >> n >> k;
	int kAn = giaithua(n) / giaithua(n - k);
	cout << kAn;
	return 0;
}
