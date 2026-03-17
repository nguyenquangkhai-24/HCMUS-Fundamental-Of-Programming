#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}
void changeWord(char* s, int index)
{
	if (s[index] == '\0')
		return;
	if (s[index] > 90 && (index == 0 || s[index - 1] == ' '))
	{
		s[index]-=32;
		changeWord(s, index + 1);
	}
	else
	{
		if (s[index] <= 90&&s[index]!=' '&&s[index-1]!=' '&&index!=0)
		{
			s[index]+=32;
			changeWord(s,index+1);
		}
		else
			changeWord(s, index + 1);
	}
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	int ssize = size(s, 0);
	changeWord(s, 0);
	cout << s;
	delete[] s;
	return 0;
}