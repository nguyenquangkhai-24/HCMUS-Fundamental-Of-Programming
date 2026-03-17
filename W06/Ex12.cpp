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
	int minsum = 1000000000;
	int minrow = 0;
	int maxproduct = 1;
	int maxcol = 0;
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j=0;j<n;j++)
		{
			sum += a[i*n+j];
		}
		if (sum<minsum)
		{
			minsum = sum;
			minrow = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int product = 1;
		for (int j=0;j<m;j++)
		{
			product *= a[j*n+i];
		}
		if (product>maxproduct)
		{
			maxproduct = product;
			maxcol = i;
		}
	}
	cout << "Row with minimum sum: " << minrow << " (sum = " << minsum << ")" << endl;
	cout << "Column with maximum product: " << maxcol << " (product = " << maxproduct << ")" << endl;
	delete[] a;
	return 0;
}