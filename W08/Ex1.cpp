#include <iostream>
#include <string>
using namespace std;

void numberSpace(string s,int &count)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
}
int main()
{
	string s;
	getline(cin, s);
	int count = 0;
	numberSpace(s, count);
	cout << count;
	return 0;
}