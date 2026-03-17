#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n, int a)
{
	if (n < 2)
		return false;
	if (a == 1)
		return true;
	else if (n % a == 0)
		return false;
	else
		isPrime(n, --a);
}
int main()
{
	int n;
	cin >> n;
	int sqrtn = sqrt(n);
	if (isPrime(n, sqrtn))
		cout << "Prime";
	else
		cout << "Not prime";
	return 0;
}