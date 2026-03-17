#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}
void interLeaving(char* s1, char* s2, char* s3, int i, int j,int &k)
{
	if (i == size(s1, 0) && j == size(s2, 0))
	{
		s3[k] = '\0';
		return;
	}
	if (s1[i] != '\0')
	{
		s3[k] = s1[i];
		i++;
		k++;
	}
	if (s2[j] != 0)
	{
		s3[k] = s2[j];
		k++;
		j++;
	}
	interLeaving(s1, s2, s3, i, j, k);
}
int main()
{
	char* s1 = new char[1000];
	cin.getline(s1,1000);
	char* s2 = new char[1000];
	cin.getline(s2,1000);
	char* s3 = new char[1000];
	int s3size = 0;
	interLeaving(s1, s2, s3, 0, 0, s3size);
	cout << s3;
	delete[] s1;
	delete[] s2;
	delete[] s3;
	return 0;
}