#include <iostream>
using namespace std;

long long Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}
int main()
{
	int n;
	cin >> n;
	long long giaithua=Factorial(n);
	cout << giaithua;
	return 0;
}