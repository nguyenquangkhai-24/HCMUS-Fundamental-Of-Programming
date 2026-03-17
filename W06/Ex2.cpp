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
	int r;
	cin >> r;
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i!= r)
			{
				a[k++] = a[i * n + j];
			}
		}
		
	}
	cout << "Matrix after delection:" << endl;
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int index = i * n + j;
			cout << a[index] << " ";
		}
		cout << endl;
	}
	delete[] a;
	return 0;
}