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
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	int* b = new int[m * n];
	int index = 0;
	for (int i = m - 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[index] = a[i * n + j];
			index++;
		}
	}
	for (int i=0;i<m-1; i++)
	{
		for (int j=0;j<n;j++)
			{
			b[index] = a[i * n + j];
			index++;
		}
	}
	for (int i = 0; i < m * n; i++)
	{
		a[i] = b[i];
	}
	printMatrix(a, m, n);
	delete[] a;
	delete[] b;
	return 0;
}