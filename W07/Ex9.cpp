#include<iostream>
using namespace std;

int a[10000000];

void binary(int n,int *a,int &index)
{
	if (n == 0)
		return;
	else
	{
		a[index]=n%2;
		n /= 2;
		index++;
		binary(n, a,index);
	}
	
}
void reversearray(int n,int* a, int &index)
{
	binary(n, a, index);
	for (int i = 0; i < index/2; i++)
	{
		int temp = *(a + i);
		*(a + i) = *(a + (index - 1 - i));
		*(a + (index - 1 - i)) = temp;
	}
}
int main()
{
	int n;
	cin >> n;
	int count = 0;
	reversearray(n, a, count);
	for (int i = 0; i < count; i++)
		cout <<*(a + i);
	if (n == 0)
		cout << n;
	return 0;
}