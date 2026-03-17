#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}
bool theSame(char* s, int start, int end, char* word,int index)
{
	if (start >= end)
		return true;
	if (s[start] != word[index])
	{
		return false;
	}
	else
		return theSame(s, start + 1, end, word, index + 1);
}
void spacenum(char* s, int* space, int& count,int index)
{
	if (s[index] == '\0')
		return;
	if (s[index] == ' ')
	{
		space[count] = index;
		count++;
		spacenum(s, space, count, index + 1);
	}
	else
		spacenum(s, space, count, index + 1);
}
void deleteWord(char* s, int* space,char*temp, char* word, int k, int spacecount,int wordsize,int ssize,int& i)
{
	if (k == spacecount)
	{
		temp[i] = '\0';
		return;
	}
	int start, end, distance;
	if (k == -1)
	{
		start = 0;
		end = space[0];
	}
	else if (k == spacecount - 1)
	{
		start = space[k]+1;
		end = ssize;
	}
	else
	{
		start = space[k]+1;
		end = space[k + 1];
	}
	distance = end - start;
	if (distance != wordsize)
	{
		for (int j = start; j < end; j++)
		{
			temp[i] = s[j];
			i++;
		}
		if (k != spacecount - 1)
			temp[i++] = ' ';
		deleteWord(s, space, temp, word, k + 1, spacecount, wordsize, ssize, i);
	}
	else if (distance == wordsize)
	{
		if(!theSame(s, start, end, word, 0))
		{
			for (int j = start; j < end; j++)
			{
				temp[i] = s[j];
				i++;
			}
			if (k != spacecount - 1)
				temp[i++] = ' ';
			deleteWord(s, space, temp, word, k + 1, spacecount, wordsize, ssize, i);
		}
		else
			deleteWord(s, space, temp, word, k + 1, spacecount, wordsize, ssize, i);
	}

}
void copyString(char* s, char* temp,int index)
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
	int* space = new int[1000];
	char* temp = new char[1000];
	char* word = new char[1000];
	cin.getline(s, 1000);
	int spacecount = 0;
	spacenum(s, space, spacecount, 0);
	cin.getline(word, 1000);
	int ssize = size(s, 0);
	int wordsize = size(word, 0);
	int index = 0;
	deleteWord(s, space, temp, word, -1, spacecount, wordsize, ssize, index);
	copyString(s, temp, index);
	cout << s;
	delete[] s;
	delete[] space;
	delete[] temp;
	delete[] word;
	return 0;
}