#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	double giatrinhonhat;
	int vitrinhonhat;
	for (int i = 0; i < n; i++)
	{
		if(a[i]>=0)
		{
			giatrinhonhat = a[i];
			vitrinhonhat = i;
			break;
		}
	}
	for (int i = 0; i <n;i++)
	{
		if(a[i]>0&&a[i]<giatrinhonhat)
		{
			giatrinhonhat = a[i];
			vitrinhonhat = i;
		}
	}
	cout << "Smallest positive: " << giatrinhonhat << " at index " << vitrinhonhat << endl;
	return 0;
}
