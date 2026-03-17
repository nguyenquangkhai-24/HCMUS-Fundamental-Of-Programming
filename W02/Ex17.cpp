#include <iostream>
using namespace std;

int main()
{
	int d, r;
	cin >> d >> r;
	cout << "Solid Rectangle:" << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "Hollow Rectangle:" << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			if (i == 1 || i == r || j == 1 || j == d)
			{
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}