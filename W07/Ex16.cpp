#include <iostream>
using namespace std;

void printRow(int n)
{
	if (n == 0)
		return;
	else
	{
		printRow(n - 1);
		cout << n;
	}


}
void printTriangle(int n)
{
	if (n == 0)
		return;
	else
	{
		printTriangle(n - 1);
		printRow(n);
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	printTriangle(n);
	return 0;
}