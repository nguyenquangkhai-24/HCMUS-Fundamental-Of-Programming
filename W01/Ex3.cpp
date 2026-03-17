#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y, z;
	cin >> x >> y >> z;
	const double pi = acos(-1.0);
	double S1 = sin(x) + log(abs(y)) + 1;
	double S2 = cos(x + y) * sqrt(abs(z) + 1) + log10(abs(x) + 1);
	double S3 = (y * tan(x)) / (1 + pow(z, 2)) + log(abs(x - y)) + 1;
	double S4 = sqrt(abs(x) + abs(y)) + pi * cos(z) - x * y + log(abs(z)) + 1;
	double S5 = (x + y - sqrt(abs(z) + 1))* sin(y) + log(abs(x)) + abs(z) + 1 + cos(x * z) / (1 + abs(y));
	cout << "S1 = "<<S1 << endl;
	cout << "S2 = "<<S2 << endl;
	cout << "S3 = "<<S3 << endl;
	cout << "S4 = "<<S4 << endl;
	cout << "S5 = "<<S5 << endl;
	return 0;
}