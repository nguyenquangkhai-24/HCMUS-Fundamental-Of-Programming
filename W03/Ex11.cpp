#include <iostream>
using namespace std;

    void chusolama(int digit, char one, char five, char ten) 
    {
        switch (digit) 
        {
        case 9:
            cout << one << ten;
            break;
        case 8:
            cout << five << one << one << one; 
            break;
        case 7:
            cout << five << one << one; 
            break;
        case 6:
            cout << five << one; 
            break;
        case 5:
            cout << five; 
            break;
        case 4:
            cout << one << five; 
            break;
        case 3:
            cout << one << one << one;
            break;
        case 2:
            cout << one << one; 
            break;
        case 1:
            cout << one; 
            break;
        case 0:
        default:
            break;
        }
    }
    void chuyensanglama(int n)
    {
        int hangngan = n / 1000;
        for (int i = 0; i < hangngan; i++)
        {
            cout << "M";
        }
        n %= 1000;
        int hangtram = n / 100;
        chusolama(hangtram, 'C', 'D', 'M');
        n %= 100;
        int hangchuc = n / 10;
        chusolama(hangchuc, 'X', 'L', 'C');
        n %= 10;
        int hangdonvi = n;
        chusolama(hangdonvi, 'I', 'V', 'X');

    }
    int main()
    {
        int n;
        cin >> n;
        chuyensanglama(n);
        return 0;
    }




