#include <iostream>
using namespace std;

int reduceCollatz(int n, int &count)
{
	if (n == 1)
		return count;
	else if (n % 2 != 0)
	{
		count++;
		n = 3 * n + 1;
		return reduceCollatz(n, count);
	}
	else if (n % 2 == 0)
	{
		count++;
		n = n/2;
		return reduceCollatz(n, count);
	}
}
int main()
{
	int n;
	cin >>n;
	int count = 0;
	reduceCollatz(n, count);
	cout << count;
	return 0;
}
