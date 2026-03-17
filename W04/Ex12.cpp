#include <iostream>
using namespace std;

int uocchunglonnhat(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
long long boichungnhonhat(long long a, long long b)
{
	long long boichungnhonhat = (a * b) / uocchunglonnhat(a, b);
	return boichungnhonhat;
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
	int uocchung = a[0];
	int boichung = a[0];
	for (int i = 1; i < n; i++)
	{
		uocchung = uocchunglonnhat(uocchung, a[i]);
		boichung = boichungnhonhat(boichung, a[i]);
	}
	cout << "GCD = " << uocchung<<" ";
	cout << "LCM = " << boichung;
	return 0;
}