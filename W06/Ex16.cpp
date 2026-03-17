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
	for (int i = 0; i < n; i++)
	{
		int max = a[i];
		for (int j = 0; j < m; j++)
		{
			if (a[j*n+i] > max)
			{
				max = a[i+j*n];
			}
		}
		int* count = new int[max + 1];
		for (int k = 0; k <= max; k++)
			count[k] = 0;
		for (int j = 0; j < m; j++)
		{
			count[a[j*n+i]]++;
		}
		cout << "Column " << i << " unique: ";
		for (int k = 0; k <= max; k++)
		{
			if (count[k] == 1)
			{
				cout << k << " ";
			}
		}
		cout << endl;
		delete[] count;
		
	}
	delete[] a;
	return 0;
}
