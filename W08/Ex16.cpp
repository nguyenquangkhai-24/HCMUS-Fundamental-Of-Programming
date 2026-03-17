#include <iostream>
using namespace std;

int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}

bool palindrome(char* left, char* right)
{
	if (left > right)
		return true;
	if (*left != *right)
		return false;
	return palindrome(left + 1, right - 1);
	return true;
}
int main()
{
	char* s = new char[1000];
	cin.getline(s, 1000);
	int ssize = size(s, 0);
	char* left = s;
	char* right = s+ssize-1;
	if (palindrome(left, right))
		cout << "YES";
	else
		cout << "NO";
	delete[] s;
	return 0;
}