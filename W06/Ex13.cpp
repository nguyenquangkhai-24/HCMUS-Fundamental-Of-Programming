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
void descending(int* a, int m, int n,int column)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			if (a[j * n+column] < a[(j + 1) * n+column])
			{

				int temp = a[j * n + column];
				a[j * n + column] = a[(j + 1) * n + column];
				a[(j + 1) * n + column] = temp;
			}
		}
	}
}
void ascending(int* a, int m, int n, int column)
{
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < m - i - 1 ; j++)
		{
			if (a[j * n + column] > a[(j + 1) * n + column])
			{
				
					int temp = a[j * n + column];
					a[j * n + column] = a[(j + 1) * n + column];
					a[(j + 1) * n + column] = temp;
			}
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			descending(a,m,n,i);
		}
		else
		{
			ascending(a,m,n,i);
		}
	}
	printMatrix(a, m, n);
	delete[] a;
	return 0;
}