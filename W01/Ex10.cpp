#include <iostream>
using namespace std;
int main()
{
	int amount;
	cin >> amount;
	cout << "Amount: " << amount <<" VND"<< endl;
	if (amount%1000 !=0 || amount <1000)
	{
		cout << "Enter again" << endl;
		cin >> amount;
	}
	int namtramngan = amount / 500000;
	amount %= 500000;
	int haitramngan = amount / 200000;
	amount %= 200000;
	int mottramngan = amount / 100000;
	amount %= 100000;
	int namchucngan = amount / 50000;
	amount %= 50000;
	int haichucngan = amount / 20000;
	amount %= 20000;
	cout << "Banknotes needed: " << endl;
	cout << "500000 VND: " << namtramngan <<" notes"<< endl;
	cout << "200000 VND: " << haitramngan << " notes" << endl;
	cout << "100000 VND: " << mottramngan << " notes" << endl;
	cout << "50000 VND: " << namchucngan << " notes" << endl;
	cout << "20000 VND: " << haichucngan << " notes" << endl;
	return 0;
}