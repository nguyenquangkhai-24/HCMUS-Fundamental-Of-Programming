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
int* transposed(int* a, int m, int n)
{
	int* b = new int[n * m];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j * m + i] = a[i * n + j];
		}
	}
	delete[] a;
	return b;
}
void reverserows(int* a, int m, int n)
{
	for (int i = 0; i < m ; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			int temp = a[i * n + j];
			a[i * n + j] = a[i * n + (n-1-j)];
			a[i * n + (n-1-j)] = temp;
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	a=transposed(a, m, n);
	reverserows(a, n, m);
	printMatrix(a, n, m);
	delete[] a;
	return 0;
}