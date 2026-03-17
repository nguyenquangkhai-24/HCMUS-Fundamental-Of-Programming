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
	for (int i = 1; i < n-1; i++)
	{
		if (a[i-1]*a[i+1]==a[i])
		{
			cout << "Position: " << i << ": "<< a[i] <<" = "<<a[i-1]<<"*"<<a[i+1]<< endl;
		}
	}
	return 0;
}