#include <iostream>
using namespace std;

void print(int* temp, int size)
{
	for (int i = 0; i < size; i++)
		cout << temp[i]<<" ";
	cout << endl;
}
void Combinations(int* temp, int n, int k,int index,int* mark,int start)
{
	if (index == k)
	{
		print(temp, k);
		return;
	}
	for (int i = start; i <= n; i++)
	{
		if (mark[i] == 0)
		{
			mark[i] = 1;
			temp[index] = i;
			Combinations(temp, n, k, index + 1, mark,i);
			mark[i] = 0;
			temp[index] = 0;
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	int* mark = new int[n + 1];
	for (int i = 1; i < n + 1; i++)
		mark[i] = 0;
	int* temp = new int[k];
	int index = 0;
	int start = 1;
	Combinations(temp, n, k, index, mark,start);
	delete[] mark;
	delete[] temp;
	return 0;
}