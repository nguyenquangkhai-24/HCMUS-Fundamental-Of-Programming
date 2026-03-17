#include <iostream>
using namespace std;

int count(char* s, int i,int occur)
{
	if (s[i] == '\0')
		return occur;
	if (s[i] == 'a')
		occur+=1;
	count(s, i + 1, occur);
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	int occur = count(s, 0, 0);
	cout << occur;
	delete[] s;
	return 0;
}