#include <iostream>
using namespace std;

int reverse(int n, int cr)
{
	if (n < 10)
		return cr  + n;
	else
	{
		cr += n % 10;
		n /= 10;
		return reverse(n, cr * 10);
	}

}
int main()
{
	int n;
	cin >> n;
	int cr = 0;
	int rn=reverse(n,cr);
	cout << rn;
	return 0;
}