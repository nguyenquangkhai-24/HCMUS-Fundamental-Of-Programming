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
	int m;
	cin >> m ;
	int* a = new int[m * m];
	inputMatrix(a, m, m);
	int sum = 0;
	int product = 1;
	for (int i=0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j==i)
			{
				sum += a[i*m+j];
			}
			if (j+i==m-1)
			{
				product *= a[i*m+j];
			}

		}
	}
	cout << "Main diagonal sum: " << sum << endl;
	cout << "Secondary diagonal product: " << product << endl;
	delete[] a;
	return 0;
}