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
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	inputMatrix(a, m, n);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int start = x1 * n + y1;
	int end = x2 * n + y2;
	int* temp = new int[m*n];
	temp[start] = a[start];
	for (int i = y1+1; i <= y2; i++)
	{
		temp[x1*n+i] = temp[x1*n+i - 1] + a[x1*n+i];
	}
	for (int i = x1+1; i <= x2; i++)
	{
		temp[i*n+y1] = temp[(i-1)*n+y1] + a[i * n + y1];
	}
	for (int i = x1 + 1; i <=x2;i++)
	{
		for (int j = y1 +1; j <=y2; j++)
		{
			temp[i*n + j] = a[i*n + j] + max(temp[i*n+j-1],temp[(i-1)*n+j]);
		}
	}
	int result = temp[end];
	cout << "Maximum path sum: " << result << endl;
	delete[] a;
	delete[] temp;
	return 0;
}