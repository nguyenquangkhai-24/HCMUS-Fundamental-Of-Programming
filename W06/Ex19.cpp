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
void reversecolumn(int* a, int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = a[j * n + i];
			a[j * n + i] = a[(m - j - 1) * n + i];
			a[(m - j - 1) * n + i] = temp;
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	reversecolumn(a, m, n);
	printMatrix(a, m, n);
	delete[] a;
	return 0;
}