#include <iostream>
using namespace std;

void print(int* cot, int* hang, int k)
{
	for (int i = 0; i <= k; i++)
	{
		cout << "(" << hang[i] << "," << cot[i]<<")";
		cout << endl;
	}
}
void Maze(int* a, int* cot, int* hang, int i, int j, int k,int m,int n,bool &flag)
{
	cot[k] = j;
	hang[k] = i;
	a[i*n+j] = 0;
	if (i == m - 1 && j == n - 1)
	{
		print(cot, hang, k);
		cout << endl;
		flag = true;
		a[i * n + j] = 1;
	}
	if (i-1>=0&&a[(i - 1) * n + j ]==1)
		Maze(a, cot, hang, i - 1, j, k + 1, m, n, flag);
	if (j-1>=0&&a[i * n + (j - 1)] == 1)
		Maze(a, cot, hang, i, j - 1, k + 1, m, n, flag);
	if (i + 1 <= m-1 && a[(i + 1) * n + j] == 1)
		Maze(a, cot, hang, i + 1, j, k + 1, m, n,flag);
	if (j + 1 <= n-1 && a[i * n + j+1] == 1)
		Maze(a, cot, hang, i, j + 1, k + 1, m, n,flag);
	if ((i + 1<=m-1)&& (j + 1<=n-1) && a[(i + 1) * n + j + 1] == 1)
		Maze(a, cot, hang, i + 1, j + 1, k + 1, m, n,flag);
	a[i * n + j] = 1;
}
int main()
{
	int m, n;
	cin >> m >> n;
	int* a = new int[m * n];
	for (int i = 0; i < m * n; i++)
		cin >> a[i];
	int* cot = new int[100];
	int* hang = new int[100];
	int k = 0;
	bool flag;
	Maze(a, cot, hang, 0, 0, k, m, n, flag);
	if (!flag)
		cout << "No path";
	delete[] a;
	delete[] cot;
	delete[] hang;
	return 0;
}