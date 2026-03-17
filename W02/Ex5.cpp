#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sochinhphuong = sqrt(n);
	if (sochinhphuong * sochinhphuong == n)
	{
		cout << n << " is a perfect square";
	}
	else
	{
		cout << n << " is not a perfect square";
	}
	return 0;
}