#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int b[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int distance = 0;
	int count = 0;
	cout << "Distance: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cout << abs(a[i] - a[j]) << " ";
			distance += abs(a[i] - a[j]);
			b[count]=abs(a[i] - a[j]);
			count++;
		}
	}
	double average = (double)distance / count;
	cout << "Average = (";
	for (int i = 0; i < count; i++)
	{
		if (i > 0)
		{
			cout << " + ";
		}
		cout << b[i];
	}
	cout << ")/" << count << " = " << average;
	return 0;

}