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
int main()
{
	int a, b;
	cin >> a >> b;
	int uocchung=uocchunglonnhat(a,b);
	
	int boichungnhonhat = (a * b) / uocchung;
	cout << "GCD: " << uocchung << "," << "LCM: " << boichungnhonhat;
	return 0;
}