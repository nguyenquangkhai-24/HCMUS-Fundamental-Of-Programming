#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

int findWord(char* s,int n,int count,int index)
{
	if (s[index] == '\0')
		return index;
	if (s[index] == ' ')
	{
		count++;
		if (count == n)
			return index + 1;
	}
	return findWord(s, n, count, index + 1);
}
void insertWord(char* s1, char* s2, char* s3, int index)
{
	int k = 0;
	for (int i = 0; i < index; i++)
	{
		s3[k] = s1[i];
		k++;
	}
	if (s1[index - 1] != ' ')
	{
		s3[k] = ' ';
		k++;
	}
	int s2size = size(s2, 0);
	for (int i = 0; i < s2size; i++)
	{
		s3[k] = s2[i];
		k++;
	}
	if (s2[s2size - 1] != ' ')
	{
		s3[k] = ' ';
		k++;
	}
	int s1size = size(s1, 0);
	for (int i = index; i < s1size; i++)
	{
		s3[k] = s1[i];
		k++;
	}
	s3[k] = '\0';
}
int main()
{
	char* s1 = new char[1000];
	char* s2 = new char[1000];
	char* s3 = new char[1000];
	cin.getline(s1, 1000);
	cin.getline(s2, 1000);
	int n;
	cin >> n;
	int index = findWord(s1,n,0,0);
	insertWord(s1, s2, s3, index);
	cout << s3;
	delete[] s1;
	delete[] s2;
	delete[] s3;
	return 0;
	
}