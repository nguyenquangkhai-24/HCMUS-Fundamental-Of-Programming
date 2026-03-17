#include <iostream>
#include <cmath>
using namespace std;

int chuso(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
int reversed(int n)
{
	int digit;
	int daonguoc = 0;
	while (n != 0)
	{
		digit = n % 10;
		daonguoc += digit * pow(10, chuso(n) - 1);
		n /= 10;
	}
	return daonguoc;
}
void solanxuathien(int n)
{
	int xuathien = n % 10;
	int count = 0;
	int digit;
	while (n != 0)
	{
		digit = n %10;
		if (digit == xuathien)
		{
			count++;
		}
		n /= 10;
		
	}
	cout << count;
}
bool daxuathien(int a,int b)
{	
	int digit;
	while (a != 0)
	{
		digit = a % 10;
		if (digit == b)
		{
			return true;
		}
		a /= 10;
	}
	return false;
}

void digit(int n)
{
	int digit;
	int daonguoc = reversed(n);
	int sodaco = 0;
	while (daonguoc != 0)
	{	
		digit = daonguoc%10;
		if (daxuathien(sodaco,digit))
		{	
			sodaco += digit * (int)pow(10, chuso(daonguoc)-1);
			daonguoc /=10;
			continue;
		}
		cout << digit << ": ";
		solanxuathien(daonguoc);
		cout << " ";
		sodaco += digit * (int)pow(10, chuso(daonguoc) - 1);
		daonguoc /=10;
		
	}
}
int main()
{
	int a;
	cin >> a;
	digit(a);
	return 0;
}