#include <iostream>
using namespace std;

int main()
{
	int h;
	cin >> h;
	cout << "Solid isosceles triangle :" << endl;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h - i; j++)
		{
			cout << " ";
		}
		for (int f=1;f<=(2*i-1);f++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "Hollow isosceles triangle :" << endl;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h - i; j++)
		{
			cout << " ";
		}
		for (int f = 1; f <= (2 * i - 1); f++)
		{
			if (f == 1 || f == (2 * i - 1) || i == h)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}