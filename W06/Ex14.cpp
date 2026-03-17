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
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			int index = i * n + j;
			cout << a[index] << " ";
		}
		cout << endl;
	}
}
bool isPerfectNum(int x)
{
	if (x < 1) return false;
	int sum = 0;
	for (int i = 1; i <x; i++)
	{
		if (x % i == 0)
		{
			sum += i;
		}
	}
	if (sum == x) return true;
	return false;
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int* temp = new int[m];
		for (int j = 0; j < m; j++)
		{
			int index = j*n+i;
			if (isPerfectNum(a[index]))
			{
				temp[count] = a[index];
				count++;
			}
		}
		for (int j = 0; j < count - 1; j++)
		{
			for (int k = 0; k < count - j - 1; k++)
			{
				if (temp[k] > temp[k + 1])
				{
					int t = temp[k];
					temp[k] = temp[k + 1];
					temp[k + 1] = t;
				}
			}
		}
		int k = 0;
		for (int j = 0; j < m; j++)
		{
			int index = j * n + i;
			if (isPerfectNum(a[index]))
			{
				a[index] = temp[k];
				k++;
			}
		}
		delete[] temp;
	}
	printMatrix(a, m, n);
	delete[]a;
	return 0;
}