#include <iostream>
using namespace std;

bool containDigit(char* s, int index)
{
	if (s[index] == ' ')
		return false;
	if (s[index] >= 48 && s[index] <= 57)
		return true;
	containDigit(s, index + 1);
}
void extractDigit(char* s,char* digit, int index,int count)
{
	if (!containDigit(s,0))
	{
		cout << "No";
		return;
	}
	if (s[index] == '\0')
	{
		digit[count - 1] = '\0';
		return;
	}
	else
	{
		if (s[index] >= 48 && s[index] <= 57)
		{
			digit[count] = s[index];
			count++;
			digit[count] = ' ';
			count++;
			extractDigit(s, digit, index + 1, count);
		}
		else
			extractDigit(s, digit, index + 1, count);
	}
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	char* digit = new char[1000];
	extractDigit(s, digit, 0, 0);
	cout << digit;
	delete[] s;
	delete[] digit;
	return 0;
}