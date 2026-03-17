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
	int sum = 0;
	int count = 0;
	int batdau = 0;
	for (int i = 0; i < n; i++)
	{	
		int tong = 0;
		for (int j = i; j < n; j++)
		{
			tong += a[j];
			if (tong > sum)
			{
				sum = tong;
				count = j - i + 1;
				batdau = i;
			}
		}
	}
	cout << "Max-sum subarray: [";
	for (int i = batdau; i < count+batdau; i++)
	{
		cout << a[i] << " ";
	}
	cout << "]\n";
	cout << "Sum = " << sum;
}