#include <iostream>
using namespace std;

int used[1000] = { 0 };
void print(int* a, int n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i]<<" ";
	cout << endl;
}
void permutations(int* a, int n, int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (used[j] == 0)
		{
			a[i] = j;
			used[j] = 1;

			if (i == n)
				print(a, n);
			else
				permutations(a, n, i + 1);
			used[j] = 0;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 1];
	permutations(a, n, 1);
	delete[] a;
	return 0;
}