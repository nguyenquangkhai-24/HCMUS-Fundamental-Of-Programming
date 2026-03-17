#include <iostream>
using namespace std;

int main()
{
	int fivedigitnumbers;
	cin >> fivedigitnumbers;
	if (fivedigitnumbers<10000|| fivedigitnumbers>99999)
	{
		cout << "Enter again" << endl;
		cin >> fivedigitnumbers;
	}
	int sum = 0;
	for (int i = 1; i <= 5; i++)
	{
		sum += fivedigitnumbers % 10;
		fivedigitnumbers /= 10;
	}
	// Tổng từng chữ số  của 1 số có 5 chữ số luôn nhỏ hơn hoặc bằng 45 vì số có 5 chữ số lớn nhất là 99999 và tổng của nó là 45
	// Nên 2 chữ số cuối cùng của tổng là chính nó.
	cout << "Sum of digits: " << sum << endl;
	cout << "Last two digits: " << sum << endl;
	return 0;



}