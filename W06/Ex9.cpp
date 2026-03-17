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
	int sum = 0;
	for (int i=0;i<m*n;i++)
	{
		sum += a[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i>0&&i<m-1)&&(j>0&&j<n-1))
			{
				sum -= a[i*n+j];
			}
		}
	}
	cout << "Border sum: " << sum << endl;
	delete[] a;
	return 0;
}