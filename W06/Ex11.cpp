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
	int* maxhang = new int[m];
	int* maxcot = new int[n];
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		int max = a[i * n];
		for (int j = 0; j < n; j++)
		{
			if (a[i * n + j]>max)
			{
				max = a[i * n + j];
			}
		}
		maxhang[i] = max;
	}
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
		maxcot[i] = max;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int index = i * n + j;
			if (a[index] == maxhang[i] && a[index] == maxcot[j])
				count++;
		}
	}
	cout << "Number of Queen elements: " << count << endl;
	delete[] a;
	delete[] maxhang;
	delete[] maxcot;
	return 0;
}