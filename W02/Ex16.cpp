#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool namnhuan(int nam)
{
	if ((nam % 100 != 0 && nam % 4 == 0) || nam % 400 == 0)
		return true;
	return false;
}

int ngaytrongthang(int thang, int nam)
{
	if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
		return 30;
	else if (thang == 2)
	{
		if (namnhuan(nam))
			return 29;
		else
			return 28;
	}
	else
		return 31;
}
int main()
{
	int ngay, thang, nam,n;
	cin >> nam >> thang >> ngay >> n;
	int ngaytoida = ngaytrongthang(thang, nam);
	int thangtoida = 12;
	int thangtoithieu=1;
	int ngaytoithieu=1;
    if (n>0)
    {
	for (int i = 1; i <= n; i++)
	{
		ngay += 1;
		ngaytoida = ngaytrongthang(thang,nam);
		if (ngay > ngaytoida)
		{
			ngay = 1;
			thang += 1;
		}
		if (thang > thangtoida)
		{
			thang = 1;
			ngay = 1;
			nam += 1;
		}

	}
    }
    else if (n<0)
    {
        for (int i=1;i<=abs(n);i++)
        {
            ngay-=1;
            if (ngay<ngaytoithieu)
            {   thang-=1;
            if (thang<thangtoithieu)
            {   nam -= 1;
                thang=thangtoida;

            }
            ngay=ngaytrongthang(thang,nam);
            }
        }
    }
	cout << "New date: " << nam << "-" << setw(2) << setfill('0') << thang << "-" << setw(2) << setfill('0')<< ngay;
}
