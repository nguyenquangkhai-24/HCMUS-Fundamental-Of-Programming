#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Before swap: a = " << a << ", b = " << b << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "After swap (method 1): a = " << a << ",b = " << b << endl;
	b = a;
	a = temp;
	a += b;
	b = a - b;
	a = a - b;
	cout << "After swap (method 2): a = " << a << ",b = " << b << endl;
	return 0;

}