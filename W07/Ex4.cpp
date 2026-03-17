#include <iostream>
using namespace std;

long long sum(int n)
{
	if (n == 0)
		return n;
	else
		return n + sum(n - 1);
}
long long product(int n)
{
	if (n == 1)
		return n;
	else
		return n * product(n - 1);
}
int main()
{
	int n;
	cin >> n;
	int S = sum(n);
	int P = product(n);
	cout << "Sum = " <<S<< endl;
	cout << "Product = " << P;
	return 0;
}