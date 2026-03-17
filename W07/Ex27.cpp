#include <iostream>
using namespace std;

void way(int* u, int* v)
{
	u[0] = -1;v[0] = 2;
	u[1] = -1;v[1] = -2;
	u[2] = -2;v[2] = -1;
	u[3] = -2;v[3] = 1;
	u[4] = 1;v[4] = 2;
	u[5] = 1;v[5] = -2;
	u[6] = 2;v[6] = 1;
	u[7] = 2;v[7] = -1;
}

void print(int* a, int n,int* pathX,int* pathY,int count)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << *(a + i * n + j) << " ";
		cout << endl;
	}
	for (int i = 0; i < n*n; i++)
	{
		cout << "(" << pathX[i] << "," << pathY[i] << ")" << " ";
		cout << "->";
	}
}
bool foundWay(int* a, int x, int y, int n)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
	{
		if (a[x * n + y] == 0)
			return true;
	}
	return false;
}
int numberWay(int x, int y, int* u, int* v,int n,int* a)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		int tempx = x + u[i];
		int tempy = y + v[i];
		if (foundWay(a,tempx, tempy,n))
			count++;
	}
	return count;
}
bool KnightTravel(int x, int y, int move, int* u, int* v, int n,int* pathX,int* pathY,int* a)
{
	a[x * n + y] = move;
	pathX[move-1] = x;
	pathY[move-1] = y;
	if (move == n*n)
		return true;
	int nextX[8];
	int nextY[8];
	int frequent[8];
	int index = 0;
	for (int i = 0; i < 8; i++)
	{
		int tempx = x + u[i];
		int tempy = y + v[i];
		if (foundWay(a, tempx, tempy, n))
		{
			nextX[index] = tempx;
			nextY[index] = tempy;
			frequent[index] = numberWay(tempx, tempy, u, v, n,a);
			index++;
		}
	}
	for (int i = 0; i < index-1; i++)
	{
		for (int j = 0; j < index - i - 1; j++)
		{
			if (frequent[j] > frequent[j + 1])
			{
				int temp1 = nextX[j]; int temp2 = nextY[j]; int temp3 = frequent[j];
				nextX[j] = nextX[j + 1]; nextY[j] = nextY[j + 1]; frequent[j] = frequent[j + 1];
				nextX[j + 1] = temp1; nextY[j + 1] = temp2; frequent[j + 1] = temp3;
			}
		}
	}
	for (int i = 0; i < index; i++)
	{
		if (KnightTravel(nextX[i], nextY[i], move + 1, u, v, n, pathX, pathY, a))
			return true;
	}
	a[x * n + y] = 0;
	pathX[move-1] = 0;
	pathY[move-1] = 0;
	return false;
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n * n];
	for (int i = 0; i < n * n; i++)
		a[i] = 0;
	int* u = new int[8];
	int* v = new int[8];
	way(u, v);
	int x, y;
	cin >> x >> y;
	int startX = x;
	int startY = y;
	int* pathX = new int[n*n];
	int* pathY = new int[n*n];
	int move = 1;
	if (KnightTravel(startX, startY, move, u, v,n, pathX, pathY, a))
		print(a, n, pathX, pathY, move);
	else
		cout << "No path";
	delete[] a;
	delete[] u;
	delete[] v;
	delete[] pathX;
	delete[] pathY;
	return 0;

}