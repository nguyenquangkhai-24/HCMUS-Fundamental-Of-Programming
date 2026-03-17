#include <iostream>
#include <cmath>
using namespace std;

int timchuso(int n)
{
	int k = 1;
	int count = 9;
	int sobatdau = 1;
	while (n > count * k)
	{
		n -= count * k;
		count *= 10;
		k++;
		sobatdau *= 10;
	}
	n--;
	int vitri = sobatdau + (n / k);
	int chusocuavitri = n % k;
	return (vitri / (int)pow(10, k - 1 - chusocuavitri)) % 10;
}
int main()
{
	int n;
	cin >> n;
	cout << timchuso(n);
	return 0;
}