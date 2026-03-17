#include <iostream>
using namespace std;


void print(int* a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
				cout << *(a + (i - 1) * n + j - 1)<<" ";
		}
			
		cout << endl;
	}		
}
void Queen(int* a,int*cot,int*xuoi,int*nguoc, int n, int i)
{
	for (int j = 1; j <= n; j++)
	{
		
		if (cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
		{
			a[(i - 1) * n + j - 1] = 1;
			cot[j] = 1;
			xuoi[i - j + n] = 1;
			nguoc[i + j - 1] = 1;
			if (i == n)
			{
				print(a, n);
				cout << endl;
			}
			else
				Queen(a, cot, xuoi, nguoc, n, i + 1);
			a[(i - 1) * n + j - 1] = 0;
			cot[j] = 0;
			xuoi[i - j + n] = 0;
			nguoc[i + j - 1] = 0;
		}
		
		
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n * n + 1];
	int* cot = new int[n + 1];
	int* xuoi = new int[n * n+1];
	int* nguoc = new int[n * n+1];
	for (int i = 0; i < n * n; i++)
	{
		a[i] = 0;
		xuoi[i+1] = 0;
		nguoc[i+1] = 0;
	}
	for (int i = 1; i <= n; i++)
		cot[i] = 0;
	Queen(a,cot,xuoi,nguoc, n, 1);
	delete[] a;
	delete[] cot;
	delete[] xuoi;
	delete[] nguoc;
	return 0;

}