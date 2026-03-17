#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double tong = 0;
	for (int i=n; i>=1; i--)
	{
		tong = sqrt(i + tong);
	}
	cout << tong;
	return 0;
}