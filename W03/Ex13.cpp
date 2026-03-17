#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	int F0 = 0;
	int F1 = 1;
	int Fn;
	if (n == 0) return F0;
	if (n == 1) return F1;
	for (int i = 2; i <= n; i++)
	{
		Fn = F1 + F0;
		F0 = F1;
		F1 = Fn;
	}
	return Fn;
}
int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n);
}