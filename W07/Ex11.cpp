#include <iostream>
using namespace std;

int numberdigit(int n, int count)
{
	if (n < 10)
		return count + 1;
	else
	{
		count += 1;
		return numberdigit(n / 10, count);
	}

}
int main()
{
	int n;
	cin >> n;
	int count = 0;
	int digit = numberdigit(n, count);
	cout << digit;
	return 0;
}
