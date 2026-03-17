#include <iostream>
using namespace std;

int size(char* s, int& count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

void mergeString(char* s1, char* s2,int s1Length,int s2Length,int i)
{
	if (s2[i]=='\0')
	{
		s1[i + s1Length] = '\0';
		return;
	}
	s1[i + s1Length] = s2[i];
	mergeString(s1, s2, s1Length, s2Length, i + 1);
}
int main()
{
	char* s1=new char[1000];
	char* s2=new char[1000];
	cin.getline(s1, 1000);
	cin.getline(s2, 1000);
	int s1Length = 0;
	size(s1, s1Length);
	int s2Length = 0;
	size(s2, s2Length);
	mergeString(s1, s2, s1Length, s2Length, 0);
	cout << s1;
	delete[] s1;
	delete[] s2;
	return 0;
}