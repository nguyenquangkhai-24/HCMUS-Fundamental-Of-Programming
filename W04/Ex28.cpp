#include <iostream>
using namespace std;

void sapxep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int n,k;
	cin >> n>>k;
	int a[1000];
	int b[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
	}
	if (n<k||n>k)
	{
		cout << "b is not a permutation of a";
		return 0;
	}
	sapxep(a, n);
	sapxep(b, k);
	bool equal;
	for (int i=0,j=0;i<n,j<k;i++,j++)
	{
		equal= true;
		if (a[i]!=b[j])
		{
			equal = false;
		}
	}
	if (equal)
	{
		cout << "b is a permutation of a";
	}
	else
	{
		cout << "b is not a permutation of a";
	}
	return 0;
}