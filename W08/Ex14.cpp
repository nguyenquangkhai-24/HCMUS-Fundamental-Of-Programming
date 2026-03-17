#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

bool isFind(char* temp, int count,char word)
{
	for (int i = 0; i < count; i++)
	{
		if (temp[i] == word)
			return true;
	}
	return false;
}
int commonChar(char* s1, char* s2, char* temp,int s1size,int s2size,int index,int count)
{
	for (int i = 0; i < s1size; i++)
	{
		for (int j = 0; j < s2size; j++)
		{
			if (s2[j] == s1[i] && !isFind(temp, index, s1[i]))
			{
				temp[index] = s1[i];
				index++;
				count++;
			}
		}
	}
	return count;
	
}
int main()
{
	char* s1 = new char[1000];
	char* s2 = new char[1000];
	cin.getline(s1, 1000);
	cin.getline(s2, 1000);
	char* temp = new char[1000];
	int s1size = size(s1, 0);
	int s2size = size(s2, 0);
	int count=commonChar(s1, s2, temp, s1size, s2size, 0, 0);
	cout << count;
	delete[] s1;
	delete[] s2;
	delete[] temp;
	return 0;
		
}