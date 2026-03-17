#include <iostream>
using namespace std;

int giatrinhonhat(int x, int y)
{
	return (x < y ? x : y);
}
int giatrilonnhat(int x, int y)
{
	return (x > y ? x : y);
}

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int sum = a[0];
	for (int i = 0; i < n; i++)
	{
		int tong = 0;
		int min = 200000;
		for (int j = i; j < n; j++)
		{
			tong += a[j];
			min = giatrinhonhat(min, a[j]);
			int tongkhongxoa = tong;
			int tongxoa = tongkhongxoa;
			if (i != j)
			{
				tongxoa -= min;
			}
			sum = giatrilonnhat(sum, tongkhongxoa);
			sum = giatrilonnhat(sum, tongxoa);
				
		}

	}
	cout << sum;
}