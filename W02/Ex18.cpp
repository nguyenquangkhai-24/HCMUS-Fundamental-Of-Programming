#include <iostream>
using namespace std;

int main()
{
	int h;
	cin >> h;
	cout << "Solid right isosceles triangle :" << endl;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "Hollow right isosceles triangle :" << endl;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == i ||j==1||i==h)
			{
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}