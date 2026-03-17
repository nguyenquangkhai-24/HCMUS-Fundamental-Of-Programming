#include <iostream>
using namespace std;

void alternate(char* s, int i)
{
	if (s[i] == '\0')
		return;
	if (i % 2 == 0 && s[i] > 90)
		s[i] -= 32;
	else if (i % 2 == 1 && s[i] <= 90)
		s[i] += 32;
	alternate(s, i + 1);
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	alternate(s, 0);
	cout << s;
	delete[] s;
	return 0;
}