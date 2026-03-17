#include <iostream>
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
	int giatrinhonhat = a[0];
	int vitrinhonhat = 0;
	int giatrilonnhat = a[0];
	int vitrilonnhat = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < giatrinhonhat)
		{
			giatrinhonhat = a[i];
			vitrinhonhat = i;
		}
		if (a[i] > giatrilonnhat)
		{
			giatrilonnhat = a[i];
			vitrilonnhat = i;
		}
	}
	cout << "Min: " << giatrinhonhat << " at index " << vitrinhonhat << endl;
	cout << "Max: " << giatrilonnhat << " at index " << vitrilonnhat << endl;
}