#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

void savespace(char* s, int* space, int i, int& j, int ssize)
{
	if (s[i] == '\0')
	{
		return;
	}
	if (s[i] == ' ')
	{
		space[j] = i;
		j += 1;
		savespace(s, space, i + 1, j, ssize);
	}
	else
		savespace(s, space, i + 1, j, ssize);
}
void reverseWord(char* s,char* result, int* space,int k,int count,int size,int index)
{
	if (k<-1)
	{ 
		result[index] = '\0';
		return;
	}
	int start;
	int end;
	if (k == -1)
	{
		start = 0;
		if (count > 0) end = space[0];
		else end = size-1;
	}
	else if (k == count - 1)
	{
		start = space[k]+1;
		end = size-1;
	}
	else
	{
		start = space[k];
		end = space[k + 1];
	}
	for (int i = start; i <= end; i++)
	{
		result[index] = s[i];
		index++;
	}
	reverseWord(s, result, space, k - 1, count, size,index);
	
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	char* result = new char[1000];
	int* space = new int[1000];
	int ssize = size(s, 0);
	int count = 0;
	savespace(s, space, 0, count, ssize);
	reverseWord(s, result, space, count + 1 - 2, count, ssize, 0);
	cout << result;
	delete[] s;
	delete[] result;
	delete[] space;
	return 0;
}