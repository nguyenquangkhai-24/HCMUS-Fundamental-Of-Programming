#include <iostream>
using namespace std;

void deleteWord(char* s, char* temp, int &index, int i,char word)
{
	if (s[i] == '\0')
		return;
	if (s[i]!=word)
	{
		temp[index] = s[i];
		index++;
		deleteWord(s, temp, index, i + 1,word);
	}
	else
		deleteWord(s, temp, index, i + 1,word);
}
void copyS(char* s, char* temp,int index)
{
	for (int i = 0; i < index; i++)
	{
		s[i] = temp[i];
	}
	s[index] = '\0';
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	char* temp = new char[1000];
	char word;
	cin >> word;
	int size=0;
	deleteWord(s, temp, size, 0,word);
	copyS(s, temp, size);
	cout << s;
	delete[] s;
	delete[] temp;
	return 0;
}