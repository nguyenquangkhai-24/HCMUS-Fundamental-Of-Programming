#include <iostream>
using namespace std;


void removeSpace(char* s, char* sub, int i, int &count)
{
	if (*(s + i) == '\0')
	{
		*(sub + count) = '\0';
		return;
	}
	if (s[i] != ' ')
	{
		sub[count] = s[i];
		count++;
		i++;
		removeSpace(s, sub, i, count);
	}
	else
	{
		if (count > 0 && s[i] == ' ' && sub[count - 1] != ' ')
		{
			sub[count] = s[i];
			i++;
			count++;
			removeSpace(s, sub, i, count);
		}
		else
			removeSpace(s, sub, i + 1, count);
	}
}
int main()
{
	char* s = new char[1000];
	char* sub = new char[1000];
	cin.getline(s, 1000);
	int count = 0;
	removeSpace(s, sub, 0, count);
	for (int i = 0; i < count; i++)
		s[i] = sub[i];
	s[count] = '\0';
	cout << s;
	delete[] s;
	delete[] sub;
	return 0;
}