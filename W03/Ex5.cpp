#include <iostream>
using namespace std;

int uocchunglonnhat(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void rutgon(int& tu, int& mau)
{
	int ucln = uocchunglonnhat(abs(tu), abs(mau));
	tu /= ucln;
	mau /= ucln;
	if (mau < 0)
	{
		tu = -tu;
		mau = -mau;
	}
	if (tu == 0)
	{
		cout << "0";
	}
	if (tu != 0)
	{
		if (mau == 1)
		{
			cout << tu;
		}
		if (mau!=1)
		{
			cout << tu << "/" << mau;
		}
	}
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int tutong = a * d + b * c;
	int mautong = b * d;
	cout << "Sum: ";
	rutgon(tutong, mautong); cout << endl;
	int tuhieu = a * d - b * c;
	int mauhieu = b * d;
	cout << "Difference: ";
	rutgon(tuhieu, mauhieu); cout << endl;
	int tutich = a * c;
	int mautich = b * d;
	cout << "Product: ";
	rutgon(tutich, mautich); cout << endl;
	int tuthuong = a * d;
	int mauthuong = b * c;
	cout << "Quotient: ";
	rutgon(tuthuong, mauthuong); cout << endl;
}