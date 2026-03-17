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
	int o;
	cin >> o;
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	int p, q;
	cin >> p >> q;
	int* b = new int[p * q];
	inputMatrix(b, p, q);
	int* c = new int[m * n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (o == 1)
			{
				c[i * n + j] = a[i * n + j] + b[i * n + j];
			}
			else if (o == 2)
			{
				c[i * n + j] = a[i * n + j] - b[i * n + j];
			}
			else if (o == 3)
			{
				c[i * n + j] = a[i * n + j] * b[i * n + j];
			}
		}
	}
	printMatrix(c, m, n);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}