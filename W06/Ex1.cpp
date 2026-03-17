#include <iostream>
using namespace std;

int main()
{
	int m, n;
	int* a;
	cin >> m >> n;
	a = new int[m * n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int index = i * n + j;
			cin >> a[index];
		}
	}
	cout << "Matrix:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int index = i * n + j;
			cout << a[index]<<" ";
		}
		cout << endl;
	}
	delete[] a;
	return 0;
}