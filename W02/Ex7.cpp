
#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        count+=1;
    }
    int solonnhat = a[0];
    int sonhonhat = a[count-1];
    for (int i = 0; i < count; i++)
    {
        if (a[i]>=solonnhat)
        {
            solonnhat = a[i];
        }
    }
    for (int i = count - 1; i >= 0; i--)
    {
        if (a[i]<=sonhonhat)
        {
            sonhonhat = a[i];
        }
    }
    cout << "Smallest: " << sonhonhat << ", Largest:" << solonnhat;
    return 0;
    
}

