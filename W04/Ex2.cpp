#include <iostream>
using namespace std;

int main()
{
	int n, x, y;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x >> y;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
			cout << a[i] << " ";
	}
	return 0;
}