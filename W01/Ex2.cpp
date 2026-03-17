#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b<<endl;
	cout << a << " * " << b << " = " << a * b<<endl;
	cout << a << " / " << b << " = " <<setprecision(2)<<fixed<< (float)a / b << endl;
		return 0;

}