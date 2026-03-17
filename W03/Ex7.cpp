#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n)
{
	int can = sqrt(n);
	if (can * can == n) return true;
	return false;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Perfect Squares: ";
	for (int i = a; i <= b; i++)
	{
		if (isPerfectSquare(i))
		{
			cout << i << " ";
		}
	}
	return 0;
}