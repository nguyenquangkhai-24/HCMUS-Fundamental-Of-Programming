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
	cout << "Subarray: ";
	for (int i = 0; i < n; i++)
	{
		int tong = 0;
		for (int j = i; j < n; j++)
		{
			tong += a[j];
			if (tong == k)
			{
				cout << "[";
				for (int k = i; k <= j; k++)
				{
					cout << a[k]<<" ";
				}
				cout << "]";
				cout << endl;
			}
		}
	}
	return 0;
}