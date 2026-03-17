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
	int k;
	cin >> k;
	int dodai = 0;
	int batdau = 0;;
	for (int i = 0; i < n; i++)
	{
		int tong = 0;

		for (int j = i; j < n; j++)
		{
			tong += a[j];
			if (tong % k == 0)
			{
				int length = j - i + 1;
				if (length > dodai)
				{
					dodai = length;
						batdau = i;
				}
			}
		}
	}
	cout << dodai << "(Array = [";
	for (int i = batdau; i < batdau + dodai; i++)
	{
		cout << a[i]<<" ";
	}
	cout << "])";
	return 0;
}