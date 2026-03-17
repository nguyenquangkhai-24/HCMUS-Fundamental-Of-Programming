#include <iostream>
#include <cmath>
using namespace std;

int chuso(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
int reversed(int n)
{
	int digit;
	int daonguoc = 0;
	while (n != 0)
	{
		digit = n % 10;
		daonguoc += digit * pow(10, chuso(n) - 1);
		n /= 10;
	}
	return daonguoc;
}
int main()
{
	int a;
	cin >> a;
	int sodaonguoc = reversed(a);
	int binhphuong = pow(sodaonguoc, 2);
	cout << binhphuong;
	return 0;
}