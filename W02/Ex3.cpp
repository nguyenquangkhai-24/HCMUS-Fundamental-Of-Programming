#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = n;
	int tonguoc = 0;
	for (int i=1;i<n;i++)
	{
		if (n % i == 0)
			tonguoc += i;
	}
	if (n == tonguoc)
		cout << n << " is a perfect number";
	else
		cout << n << " is not a perfect number";
	return 0;
}