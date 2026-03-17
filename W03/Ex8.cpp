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
bool isArmstrong(int n)
{
	int sum = 0;
	int digit;
	int nn = n;
	while (n != 0)
	{
		digit = n % 10;
		sum += pow(digit, chuso(nn));
		n /= 10;
	}
	if (sum == nn) return true;
	return false;

}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Armstrong Numbers: ";
	for (int i = a; i <= b; i++)
	{
		if (isArmstrong(i))
		{
			cout << i << " ";
		}
	}
	return 0;
}