#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int left,int right)
{
	if (left >= right)
		return;
	else
	{
		int temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		reverse(s, left+1, right-1);
	}
}
int main()
{
	string s;
	cin >> s;
	int left = 0;
	int right = s.length()-1;
	reverse(s,left,right);
	cout << s;
	return 0;
}