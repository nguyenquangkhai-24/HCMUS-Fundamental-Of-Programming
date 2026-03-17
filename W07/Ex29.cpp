#include <iostream>
using namespace std;

void print(int* a)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << a[i * 9 + j]<<" ";
		cout << endl;
	}
}
bool find(int* a, int num, int startx, int starty)
{
	for (int i = 0; i < 9; i++)
	{
		if (a[startx * 9 + i] == num)
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (a[i * 9 + starty] == num)
			return false;
	}
	int start33x = startx-startx % 3;
	int start33y = starty-starty % 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[(start33x + i) * 9 + (start33y + j)] == num)
				return false;
		}
	}
	return true;
}
bool Sudoku(int* a, int index)
{
	int x = index / 9;
	int y = index % 9;
	if (index == 81)
	{
		return true;
	}
	if (a[index] != 0)
		return Sudoku(a, index+1);
	for (int i = 0; i <= 9; i++)
	{
		if (find(a, i, x, y))
		{
			a[index] = i;
			if (Sudoku(a, index + 1))
				return true;
		}
		a[index]=0;
	}
	return false;
}
int main()
{
	int* a = new int[81];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> a[i*9+j];
	}
	int index;
	for (int i = 0; i < 81; i++)
	{
		if (a[i] == 0)
		{
			index = i;
			break;
		}
	}
	if (Sudoku(a, index))
		print(a);
	delete[] a;
	return 0;
}