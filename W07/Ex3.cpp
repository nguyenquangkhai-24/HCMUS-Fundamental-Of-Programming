#include <iostream>
using namespace std;


long long Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);

}
int main()
{
	int n;
	cin >> n;
	long long fibonacci = Fibonacci(n);
	cout << fibonacci;
	return 0;
}