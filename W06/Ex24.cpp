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
void rotate(int* a, int m, int n)
{
	int* top = new int[n];
	for (int i = 0; i < n; i++)
	{
		top[i] = a[i];
	}
	int* left = new int[m];
	for (int i = 0; i < m; i++)
	{
		left[i] = a[i * n];
	}
	int* bottom = new int[n];
	for (int i = 0; i < n; i++)
	{
		bottom[i] = a[(m - 1) * n + i];
	}
	int* right = new int[m];
	for (int i = 0; i < m; i++)
	{
		right[i] = a[i * n + (n - 1)];
	}
	for (int i = 0; i < m; i++)
	{
		a[i * n + (n - 1)] = top[i];
	}
	for (int i = n-1; i >=0; i--)
	{
		a[(m - 1) * n + i] = right[n-i-1];
	}
	for (int i = m - 1; i >= 0; i--)
	{
		a[i * n] = bottom[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = left[n-1-i];
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	rotate(a, m, n);
	printMatrix(a, m, n);
	delete[] a;
	return 0;
}