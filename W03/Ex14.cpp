#include <iostream>
using namespace std;

long long giaithua(int n)
{
	long long giaithua = 1;
	for (int i = 1; i <= n; i++)
		giaithua *= i;
	return giaithua;
}
int sochuso(long long n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1;; i++)
	{
		if (sochuso(giaithua(i))==n)
		{
			cout << i<<" ";
		}
		if (sochuso(giaithua(i)) > n)
			break;
	}
	return 0;
}
