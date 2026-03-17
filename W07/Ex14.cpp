#include <iostream>
using namespace std;

int sumElement(int* a, int& sum, int index, int n)
{
	if (index == n)
		return sum;
	else
	{
		sum += *(a + index);
		return sumElement(a, sum, index+1, n);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
	int sum = 0;
	int index = 0;
	sumElement(a, sum, index, n);
	cout << sum;
	delete[] a;
	return 0;
}
