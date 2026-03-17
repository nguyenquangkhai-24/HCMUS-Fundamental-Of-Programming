#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float velocity;
	cout << "Enter velocity in m/s: ";
	cin >> velocity;
	int kmh = velocity * 3.6;
	cout << setprecision(1) << fixed << velocity << " m/s = " << setprecision(2) << fixed << kmh << " km/h" << endl;
	return 0;

}