#include <iostream>
using namespace std;

int maxElement(int* a, int &max,int index,int n)
{
	if (index == n)
		return max;
	else
	{
		if (*(a + index) > max)
		{
			max = *(a + index);
		}
		return maxElement(a, max, index + 1, n);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
	int max = *a;
	int index = 1;
	maxElement(a, max, index, n);
	cout << max;
	delete[] a;
	return 0;
}