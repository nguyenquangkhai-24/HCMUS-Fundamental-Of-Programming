#include <iostream>
using namespace std;

void print(int* temp, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << temp[i];
		if (i < size - 1)
			cout << "+";
	}
	cout << endl;
}
void Summands(int i, int value, int* temp, int size)
{
	if (value == 0)
	{
		print(temp, size);
		return;
	}
	for (int j = i; j <= value; j++)
	{
		temp[size] = j;
		Summands(j, value - j, temp, size + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int* temp = new int[n];
	int i = 1;
	int size = 0;
	Summands(i, n, temp, size);
	delete[] temp;
	return 0;

}