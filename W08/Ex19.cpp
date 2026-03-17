#include <iostream>
using namespace std;

bool isSeparated(char word)
{
	if (word == ' ' || word == '?' || word == ',' || word == ';' || word == '.' || word == '!')
		return true;
	return false;
}
int countWord(char* s, int index,int count)
{
	if (s[index] == '\0')
		return count;
	if (index == 0 || (!isSeparated(s[index]) && isSeparated(s[index - 1])))
	{
		count++;
		return countWord(s, index + 1, count);
	}
	else
		return countWord(s, index + 1, count);
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	int count = countWord(s, 0, 0);;
	cout << count;
	delete[] s;
	return 0;
}