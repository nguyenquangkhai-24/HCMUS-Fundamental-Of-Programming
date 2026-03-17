#include <iostream>
using namespace std;

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
	int count = 0;
	for (int i = 0; i < k-n; i++)
	{
		bool found = true;
		for (int j = 0; j < n; j++)
		{
			if (b[i+j]!=a[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			count++;
		}
		
	}
	cout << "Occurrences: "<<count;
}