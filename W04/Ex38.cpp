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
	cout << "Subarray: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = i; j < n; j++)
		{
			cout << "[";
			for (int k = i; k <= j; k++)
			{
				cout << a[k]<<" ";
			}
			cout << "]";
		}
	}
}