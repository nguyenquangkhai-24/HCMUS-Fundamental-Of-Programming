#include <iostream>
using namespace std;

int mangduong(int a[], int size, int x)
{
	int count=0;
	for (int i = x; i < size; i++)
	{
		if (a[i] < 0)
			break;
		else if (a[i]>0)
			count++;
	}
	return count;
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
	int count;
	int vitri;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			vitri = i;
			count = mangduong(a, n, i);
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int count1 = mangduong(a, n, i);
		if (count1 > count)
		{
			count = count1;
			vitri = i;
		}

	}
	cout << "Longest positive subarray: ";
	for (int i = vitri; i < vitri + count; i++)
	{
		cout << a[i] << " ";
	}
	cout << "Length = " << count;
	return 0;
}
