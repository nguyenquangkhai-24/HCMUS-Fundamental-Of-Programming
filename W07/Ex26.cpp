#include <iostream>
using namespace std;

void way(int* u, int* v)
{
	u[0] = -1; v[0] = 2;
	u[1] = -1; v[1] = -2;
	u[2] = -2; v[2] = -1;
	u[3] = -2; v[3] = 1;
	u[4] = 1;  v[4] = 2;
	u[5] = 1;  v[5] = -2;
	u[6] = 2;  v[6] = 1;
	u[7] = 2;  v[7] = -1;
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << *(a + i * n + j)<<" ";
		cout << endl;
	}
}
void dich(int* u, int* v, int* aim, int x, int y,int num,int n)
{
	for (int i = 0; i < 8; i++)
	{
		int tempx = x + u[i];
		int tempy = y + v[i];
		if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < n)
		{
			aim[tempx * n + tempy] +=num;
		}
	}

}
void Knight(int* a, int k,int start,int* u,int* v,int* aim,int n)
{
	if (k == 0)
	{
		print(a, n);
		cout << endl;
		return;
	}
	for (int j = start; j < n*n; j++)
	{
		int x = j / n;
		int y = j % n;
		if (aim[j] == 0)
		{
			a[j] = 1;
			dich(u, v, aim, x, y, 1, n);
			Knight(a, k - 1, j+1, u, v,aim, n);
			a[j] = 0;
			dich(u, v, aim, x, y, -1, n);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int k = n;
	int* a = new int[n * n];
	int* aim = new int[n*n];
	int* u = new int[8];
	int* v = new int[8];
	for (int i = 0; i < n * n; i++)
	{
		a[i] = aim[i] = 0;
	}
	way(u, v);
	Knight(a, k, 0, u, v,aim, n);
	delete[] a;
	delete[] aim;
	delete[] u;
	delete[] v;
	return 0;
	

}