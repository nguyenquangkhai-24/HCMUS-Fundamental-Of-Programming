#include <iostream>
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
	int ngaynow,ngayto, thangnow,thangto, yearnow,yearto;
	cin >> yearnow>>thangnow>>ngaynow>>yearto>>thangto>>ngayto;
	int thangtoida=12;
	int count = 0;
	if (yearnow<yearto)
    {
        while(ngaynow!=ngayto||thangnow!=thangto||yearnow!=yearto)
        {
            ngaynow+=1;
            count+=1;
            if (ngaynow>ngaytrongthang(thangnow,yearnow))
            {
                ngaynow=1;
                thangnow+=1;
            }
            if (thangnow>thangtoida)
            {
                ngaynow=1;
                thangnow=1;
                yearnow+=1;
            }

        }
    }
    else if (yearnow>yearto)
    {
        while (ngayto!=ngaynow||thangto!=thangnow||yearto!=yearnow)
        {
            ngayto+=1;
            count+=1;
            if (ngayto>ngaytrongthang(thangto,yearto))
            {
                ngayto=1;
                thangto+=1;
            }
            if (thangto>thangtoida)
            {
                ngayto=1;
                thangto=1;
                yearto+=1;
            }
        }
    }
    else if(yearnow==yearto)
    {
        if (thangnow<thangto)
        {
            while (ngaynow!=ngayto||thangnow!=thangto)
            {
                ngaynow+=1;
                count+=1;
                if (ngaynow>ngaytrongthang(thangnow,yearnow))
                {
                    ngaynow=1;
                    thangnow+=1;
                }
            }
        }
        else if (thangnow>thangto)
        {
            while (ngayto!=ngaynow||thangto!=thangnow)
            {
                ngayto+=1;
                count+=1;
                if (ngayto>ngaytrongthang(thangto,yearto))
                {
                    ngayto=1;
                    thangto+=1;
                }
            }
        }
        else if(thangnow==thangto)
        {
            if (ngaynow>ngayto)
            {
                while (ngayto!=ngaynow)
                {
                    ngayto+=1;
                    count+=1;
                }
            }
            else if (ngaynow<ngayto)
            {
                while (ngaynow!=ngayto)
                {
                    ngaynow+=1;
                    count+=1;
                }
            }
        }
    }

	cout << "Days betwen: " << count;
}
