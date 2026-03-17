#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "First perfect square: ";
	for (int i = 0; i < n; i++)
	{
		int can = sqrt(a[i]);
		if (can * can == a[i])
		{
			cout << a[i] << " at index " << i << endl;
			break;
		}
	}
}