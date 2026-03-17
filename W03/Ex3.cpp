#include <iostream>
#include <cmath>
using namespace std;
bool PerfectNumber(int n)
{
	int uoc = 0;
	for (int i = 1; i <= n-1; i++)
	{
		if (n % i == 0)
		{
			uoc += i;
		}
	}
	if (uoc==n)
		return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int tich = 1;
	for (int i = 1; i <= n; i++)
	{
		if (PerfectNumber(i))
		{
			cout << i << " ";
			sum += i;
			tich *= i;
		}
			
	}
	cout << endl << "Sum = " << sum<<",";
	cout << "Product = " << tich;
}