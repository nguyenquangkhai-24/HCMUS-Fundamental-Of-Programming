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
	int* b = new int[m * n];
	int max = a[0];
	for (int i=0; i < m*n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	int* count = new int[max + 1];
	for (int i = 0; i < max+1; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < m*n; i++)
	{
			count[a[i]]++;
	}
	int frequent = count[0];
	int position = -1;
	for (int i = 0; i <= max; i++)
	{
		if (count[i]>frequent)
		{
			frequent = count[i];
			position = i;
		}
	}
	cout << "Most frequent: " << position << "(appears " << frequent << " times)" << endl;
	delete[] a;
	delete[] b;
	delete[] count;
	return 0;
}