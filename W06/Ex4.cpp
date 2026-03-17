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
	int* b = new int[n*m];
	for (int i=0;i<m;i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j * m + i] = a[i * n + j];
		}
	}
	delete[] a;
	a = b;
	printMatrix(a, n,m);
	delete[] a;
	return 0;
}