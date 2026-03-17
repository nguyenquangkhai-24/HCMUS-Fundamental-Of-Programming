#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cin>>x;
	int n=abs(x);
	int lastdigit = n % 10;
	n /= 10;
	int currentdigit;
	bool tangdan = true;
	bool giamdan = true;
	while (n > 0)
	{
		currentdigit = n % 10;
		n /= 10;
		if (currentdigit > lastdigit)
		{
			tangdan = false;
		}
		if (currentdigit<lastdigit)
		{
			giamdan = false;
		}
		if (currentdigit==lastdigit)
        {
            giamdan=false;
            tangdan=false;
        }
		lastdigit = currentdigit;
	}
	if (tangdan)
	{
		cout << "Digits are in increasing order";
	}
	else if (giamdan)
	{
		cout << "Digits are in decreasing order";
	}
	else
	{
		cout << "Digits are neither in increasing nor decreasing order";
	}
}
