#include <iostream>
using namespace std;

void printdecreasing(int n)
{
	if (n == 1)
		cout << n;
	else
	{
		cout << n<<" ";
		printdecreasing(n - 1);
	}
	
		
}
void printincreasing(int n)
{
	if (n == 1)
		cout << n<<" ";
	else
	{
		printincreasing(n - 1);
		cout << n<<" ";
	}


}
int main()
{
	int n;
	cin >> n;
	printdecreasing(n);
	cout << endl;
	printincreasing(n);
	return 0;
}