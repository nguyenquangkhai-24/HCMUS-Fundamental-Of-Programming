#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool lasonguyento = true;
	if (n<2)
	{
		lasonguyento = false;
	}
	for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i==0)
			{
				lasonguyento = false;
				break;
			}
		}
	if (lasonguyento)
		cout << n << " is a prime number";
	else
		cout << n << " is not a prime number";
	return 0;
}