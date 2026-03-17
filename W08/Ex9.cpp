#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

void reverse(char* s, int i,int size)
{
	if (i == size / 2)
		return;
	int temp = s[i];
	s[i] = s[size - 1 - i];
	s[size - 1 - i] = temp;
	reverse(s, i + 1, size);
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	int ssize = size(s, 0);
	reverse(s, 0, ssize);
	cout << s;
	delete[] s;
	return 0;
}