#include <iostream>
using namespace std;

bool isPerfectNumber(int x)
{
	int tong = 0;
	for (int i=1;i<x;i++)
	{
		if(x%i==0)
		{
			tong+=i;
		}
	}
	if(tong==x)
	{
		return true;
	}
	return false;
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
	int nhonhat;
	int vitrinhonhat;
	for (int i = 0; i < n; i++)
	{
		if(isPerfectNumber(a[i]))
		{
			nhonhat = a[i];
			vitrinhonhat = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if(isPerfectNumber(a[i])&&a[i]<nhonhat)
		{
			nhonhat = a[i];
			vitrinhonhat = i;
		}
	}
	cout << "Smallest perfect number: " << nhonhat << " at index " << vitrinhonhat << endl;
	return 0;
}