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
void sort(int *a, int m, int n)
{
	for (int i = 0; i < m * n - 1; i++)
	{
		for (int j=0;j< m * n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void rearrange(int* a, int m, int n)
{
	int top = 0;
	int bottom = m - 1;
	int left = 0;
	int right = n - 1;
	int* b = new int[m * n];
	for (int i = 0; i < m * n; i++)
	{
		b[i] = a[i];
	}
	int index = 0;
	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
		{
			a[top * n + i] = b[index++];
		}
		top++;
		for (int i = top; i <= bottom; i++)
		{
			a[i * n + right] = b[index++];
		}
		right--;
		for (int i = right; i >= left; i--)
		{
			a[bottom * n + i] = b[index++];
		}
		bottom--;
		for (int i = bottom; i >= top; i--)
		{
			a[i * n + left] = b[index++];
		}
		left++;
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	sort(a, m, n);
	rearrange(a, m, n);
	printMatrix(a, m, n);
	delete[] a;
	return 0;
}