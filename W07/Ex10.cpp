#include <iostream>
#include <string>
using namespace std;

bool palindrome(string s, int left, int right)
{
	if (s[left] != s[right])
		return false;
	else if (left >= right)
		return true;
	else
	{
		return palindrome(s, left + 1, right - 1);
	}
}
int main()
{
	string s;
	cin >> s;
	int left = 0;
	int right = s.length() - 1;
	if (palindrome(s, left, right))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
