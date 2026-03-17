#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int seconds;
	cin >> seconds;
	int hours = seconds / 3600;
	int minutes = (seconds % 3600) / 60;
	int secs = seconds % 60;
	cout << "Times: " <<setfill('0')<<setw(2)<< hours << ":" <<setw(2)<< minutes << ":" <<setw(2)<< secs << endl;
	return 0;
}