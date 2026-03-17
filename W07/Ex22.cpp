#include <iostream>
using namespace std;

void print(int *a,int  n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << endl;
}
void Binarystrings(int* a,int i,int n)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i == n)
			print(a, n);
		else
			Binarystrings(a, i + 1, n);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n+1];
	Binarystrings(a, 1, n);
	delete[] a;
	return 0;
}