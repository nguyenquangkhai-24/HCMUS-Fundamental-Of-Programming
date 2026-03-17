#include <iostream>
using namespace std;

void inputMatrix(int* a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int index = i * n + j;
			cin >> a[index];
		}
	}
}
void printMatrix(int* a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int index = i * n + j;
			cout << a[index] << " ";
		}
		cout << endl;
	}
}
void daomang (int *a, int* b, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j * m + i] =a[i*n+j] ;
		}
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	int* b = new int[m * n];
	daomang(a, b, m, n);
	for (int i=0;i<m;i++)
	{
		int min = a[i*n];
		int max = a[i*n];
		for (int j = 0; j < n; j++)
		{
			if (a[i*n+j]<min)
			{
				min = a[i*n+j];
			}
			if (a[i*n+j]>max)
			{
				max = a[i*n+j];
			}
		}
		cout << "Row " << i << ": Min = " << min << ", Max = " << max << endl;
	}
	for (int i = 0; i < n; i++)
	{
		int min = b[i*m];
		int max = b[i*m];
		for (int j = 0; j < m; j++)
		{
			if (b[i*m+j]<min)
			{
				min = b[i*m+j];
			}
			if (b[i*m+j]>max)
			{
				max = b[i*m+j];
			}
		}
		cout << "Column " << i << ": Min = " << min << ", Max = " << max << endl;
	}
	delete[] a;
	delete[] b;
	return 0;
}