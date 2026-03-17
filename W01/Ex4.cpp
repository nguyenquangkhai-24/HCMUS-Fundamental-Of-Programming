#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double w, h, a, r, x, y, z;
	const double pi = 3.1415;
	cout << "Enter width and height of the rectangle: "<<endl;
	cin >> w >> h;
	cout << "Enter side length of the square: ";
	cin >> a;
	cout << "Enter radius of the circle: ";
	cin >> r;
	cout << "Enter the sides of the triangle: "<<endl;
	cin >> x >> y >> z;
	double p = (x + y + z) / 2;
	double area = sqrt(p * (p - x) * (p - y) * (p - z));
	cout << "Rectangle - Perimeter: " << setprecision(2) << fixed << 2 * (w + h) << ", Area: " << w * h << endl;
	cout << "Square - Perimeter: " << setprecision(2) << fixed << 4*a << ", Area: " << a*a << endl;
	cout << "Circle - Perimeter: " << setprecision(2) << fixed << 2*pi*r << ", Area: " << pi*pow(r,2) << endl;
	cout << "Triangle - Perimeter: " << setprecision(2) << fixed << x+y+z << ", Area: " << area << endl;
	return 0;
	
	

}