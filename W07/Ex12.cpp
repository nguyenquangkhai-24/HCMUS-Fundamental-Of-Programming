#include <iostream>
using namespace std;

bool nondecreasing(int* a, int index,int n)
{
	if (index == n - 1)
		return true;
	else if (*(a + index) > *(a + index + 1))
		return false;
	else
		return nondecreasing(a, index + 1, n);
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
	int index = 0;
	if (nondecreasing(a, index, n))
		cout << "Yes";
	else
		cout << "No";
	delete[] a;
	return 0;
}