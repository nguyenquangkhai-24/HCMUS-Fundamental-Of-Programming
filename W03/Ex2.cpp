#include <iostream>
using namespace std;

bool uoc(int n, int i)
{
	if (n%i == 0)
		return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (uoc(n,i))
			cout << i << " ";
	}
	return 0;
}
