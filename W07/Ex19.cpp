#include <iostream>
#include <cmath>
using namespace std;

void thapHaNoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		cout << "Move disk 1 from " << A << " to " << C<<endl;
		return;
	}
	
	else
	{
		thapHaNoi(n - 1, A, C, B);
		cout << "Move disk " << n << " from " << A << " to " << C<<endl;
		thapHaNoi(n - 1, B, A, C);
	}
}
int main()
{
	int n;
	cin >> n;
	int step=(int)pow(2,n)-1;
	cout << step << endl;
	thapHaNoi(n, 'A', 'B', 'C');
	return 0;

}