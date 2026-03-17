#include <iostream>
using namespace std;


int digit(int x)
{
	int realnum = x;
	int count = 0;
	while (realnum > 0)
	{
		realnum /= 10;
		count++;
	}
	return count;
}
void mangphu(int x, int b[], int count)
{
	int realnumber = x;
	if (realnumber == 0)
	{
		b[count] = 0;
	}
	while (realnumber != 0)
	{
		b[count] = realnumber % 10;
		realnumber /= 10;
		count++;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int b[1000];
	int count = 0;
	int dem[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		mangphu(a[i], b, count);
		count += digit(a[i]);
	}
	for (int i = 0; i < count; i++)
	{
		dem[b[i]]++;
	}
	int giatrinhonhat = dem[0];
	int vitrinhonhat = 0;
	for (int i = 0; i < 10; i++)
	{
		if (dem[i] < giatrinhonhat)
		{
			giatrinhonhat = dem[i];
			vitrinhonhat = i;
		}
	}
	cout << "Least frequent digit: " << vitrinhonhat << "(appears " << giatrinhonhat << " times excecpt itself is unique)";
	return 0;

}