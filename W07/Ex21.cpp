#include <iostream>
using namespace std;

void print(int* subset, int size)
{
	for (int i = 0; i < size; i++)
		cout << subset[i] << " ";
	cout << endl;
}
void Subset(int* a, int n, int i, int* subset, int size)
{
	if (i == n)
	{
		print(subset, size);
		return;
	}
	Subset(a, n, i + 1, subset, size);
	subset[size] = a[i];
	Subset(a, n, i + 1, subset, size + 1);
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int* subset = new int[n];
		int size = 0;
		Subset(a, n, 0, subset, size);
		delete[] a;
		delete[] subset;
		return 0;
}