#include <iostream>
using namespace std;

long long luythua(int a,int b)
{
	if (b == 0)
		return 1;
	else
		return a * luythua(a, b - 1);
}
int main()
{
	int a, b;
	cin >> a >> b;
	long long somu=luythua(a, b);
	cout << somu;
	return 0;
}