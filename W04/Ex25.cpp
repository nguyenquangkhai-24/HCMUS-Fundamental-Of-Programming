#include <iostream>
using namespace std;

bool isSymmetric(double a[],int size)
{
	for (int i=0; i < size / 2; i++)
	{
		if (a[i] != a[size - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	double a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (isSymmetric(a,n))
	{
		cout << "The array is symmetric";
	}
	else
	{
		cout << "The array is not symmetric";
	}
	return 0;
}