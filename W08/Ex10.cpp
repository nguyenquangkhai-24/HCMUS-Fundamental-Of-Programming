#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

int Search(char* s, char word, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (s[i] == word)
			return i+1;
	}
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	char word;
	cin >> word;
	int ssize = size(s, 0);
	int find= Search(s, word, ssize);
	cout << find;
	delete[] s;
	return 0;
}