#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double Quantity, unitprice, total;
	cout << "Enter quantity: ";
	cin >> Quantity;
	cout << "Enter unit price: ";
	cin >> unitprice;
	total = (Quantity * unitprice)+ 0.1* (Quantity * unitprice);
	cout << "Final payment: " << round(total) << endl;
	return 0;
}