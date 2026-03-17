#include <iostream>
using namespace std;

int product(int a, int b, int count,int &sum)
{
	if (b == 0)
		return 0;
	else if (count == b)
		return sum+a;
	else
	{
		sum += a;
		count++;
		return product(a, b, count, sum);
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	int sum = 0;
	int count = 0;
	product(a, b, count, sum);
	cout << sum;
	return 0;
}
