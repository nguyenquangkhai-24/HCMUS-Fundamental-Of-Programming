#include <iostream>
using namespace std;

int main()
{
	int h;
	cin >> h;
	cout << "Diamond shape: " << endl;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h - i; j++)
		{
			cout << " ";
		}
		for (int f = 1; f <= (2 * i - 1); f++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = h - 1; i >= 1; i--)
	{
		for (int j = 1; j <= h - i; j++)
		{
			cout << " ";
		}
		for (int f = 1; f <= (2 * i - 1); f++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}