#include <iostream>
using namespace std;

void uppercase(char* s, int i)
{
	if (s[i] == '\0')
		return;
	if (s[i] > 90)
		s[i] -= 32;
	uppercase(s, i + 1);
}

int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	uppercase(s, 0);
	cout << s;
	delete[] s;
	return 0;
}