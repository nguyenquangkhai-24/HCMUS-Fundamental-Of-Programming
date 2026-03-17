#include <iostream>
using namespace std;

struct Date 
{
	int day;
	int month;
	int year;
};
struct Time
{
	int hours;
	int minutes;
};
struct Flight
{
	char* code;
	Date* date;
	Time* time;
	char* departure;
	char* arrival;
};
void inputSingleFlight(Flight& f)
{
	f.code = new char[6];
	f.date = new Date;
	f.time = new Time;
	f.departure = new char[21];
	f.arrival = new char[21];

	cout << "Nhap ma chuyen bay: ";
	cin.getline(f.code, 6);
	cout << endl;

	cout << "Nhap ngay chuyen bay: ";
	cin >> f.date->day >> f.date->month >> f.date->year;
	cout << endl;

	cout << "Nhap thoi gian chuyen bay: ";
	cin >> f.time->hours >> f.time->minutes;
	cout << endl;

	cout << "Nhap dia diem xuat phat chuyen bay: ";
	cin.ignore();
	cin.getline(f.departure, 21);
	cout << endl;

	cout << "Nhap dia diem den cua chuyen bay: ";
	cin.getline(f.arrival, 21);
	cout << endl;
}
void inputFlight(Flight* f, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap chuyen bay thu " << i + 1 << ":" << endl;
		inputSingleFlight(f[i]);
	}
}
void displayFlight(Flight* f, int n)
{
	cout << "So luong chuyen bay hien co: " << n<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Chuyen bay thu " << i + 1 << ":" << endl;
		cout << endl;
		cout << "Ma chuyen bay: " << f[i].code << endl;
		cout << endl;
		cout << "Ngay xuat phat: " << f[i].date->day << "/" << f[i].date->month << '/' << f[i].date->year << endl;
		cout << endl;
		cout << "Gio xuat phat: " << f[i].time->hours << ":" << f[i].time->minutes << endl;
		cout << endl;
		cout << "Dia diem xuat phat: " << f[i].departure << endl;
		cout << endl;
		cout << "Noi den: " << f[i].arrival << endl;
		cout << endl;
	}
}
void freeFlight(Flight& f)
{
	delete[] f.code;
	delete f.date;
	delete f.time;
	delete[] f.departure;
	delete[] f.arrival;
}
void highestFlight(Flight* f,int n)
{
	int max = -100;
	Flight ft;
	ft.date = new Date;
	for (int i = 0; i < n; i++)
	{
		int maxtemp = 0;
		for (int j = 0; j < n; j++)
		{
			if (f[i].date->day== f[j].date->day &&
				f[i].date->month== f[j].date->month &&
				f[i].date->year== f[j].date->year)
			{
				maxtemp += 1;
			}
			if (maxtemp > max)
			{
				max = maxtemp;
				ft.date->day = f[i].date->day;
				ft.date->month = f[i].date->month;
				ft.date->year = f[i].date->year;
			}
		}
	}
	cout << "So chuyen bay nhieu nhat trong ngay la: " << max << endl;
	if(max>1)
		cout << "Ngay co nhieu chuyen bay nhat la: " << ft.date->day << "/" << ft.date->month << "/"<<ft.date->year << endl;
	delete ft.date;
}
int csize(char* code, int index, int count)
{
	if (code[index] == '\0')
		return count;
	count += 1;
	csize(code, index + 1, count);
}
bool theSame(char* code1, char* code2,int index)
{
	if (csize(code1, 0, 0) != csize(code2, 0, 0))
		return false;
	if (code1[index] != code2[index])
		return false;
	if (code1[index] == '\0')
		return true;
	return theSame(code1, code2, index + 1);
}
void searchFlight(Flight* f, int n,char* code)
{
	bool search = false;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (theSame(f[i].code,code,0))
		{
			search = true;
			count += 1;
		}
	}
	cout << "Tim thay " << count << " chuyen bay voi cung ma code" << endl;
	if (search)
	{
		for (int i = 0; i < n; i++)
		{
			if (theSame(f[i].code,code,0))
			{
				cout << "Ma chuyen bay: " << f[i].code << endl;
				cout << endl;
				cout << "Ngay xuat phat: " << f[i].date->day << "/" << f[i].date->month << '/' << f[i].date->year << endl;
				cout << endl;
				cout << "Gio xuat phat: " << f[i].time->hours << ":" << f[i].time->minutes << endl;
				cout << endl;
				cout << "Dia diem xuat phat: " << f[i].departure << endl;
				cout << endl;
				cout << "Noi den: " << f[i].arrival << endl;
				cout << endl;
			}
		}
	}
}
bool inRange(Date* startday, Date* endday, Date* findday, Time* starttime, Time* endtime, Time* findtime)
{
	if (findday->year<startday->year || findday->year>endday->year)
		return false;
	else
	{
		if (findday->month<startday->month || findday->month>endday->month)
			return false;
		else
		{
			if (findday->day<startday->day || findday->day>endday->day)
				return false;
			else
			{
				if (findtime->hours<starttime->hours || findtime->hours>endtime->hours)
					return false;
				else
				{
					if (findtime->minutes<starttime->minutes || findtime->minutes>endtime->minutes)
						return false;
				}
			}
		}
	}
	return true;
}
void filterFlight(Flight* f, int n, Date* startday, Date* endday, Time* starttime, Time* endtime)
{
	for (int i = 0; i < n; i++)
	{
		if (inRange(startday, endday, f[i].date, starttime, endtime, f[i].time))
		{
			cout << "Ma chuyen bay: " << f[i].code << endl;
			cout << endl;
			cout << "Ngay xuat phat: " << f[i].date->day << "/" << f[i].date->month << '/' << f[i].date->year << endl;
			cout << endl;
			cout << "Gio xuat phat: " << f[i].time->hours << ":" << f[i].time->minutes << endl;
			cout << endl;
			cout << "Dia diem xuat phat: " << f[i].departure << endl;
			cout << endl;
			cout << "Noi den: " << f[i].arrival << endl;
			cout << endl;
		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong chuyen bay: ";
	cin >> n;
	Flight* flight = new Flight[n];
	cin.ignore();
	inputFlight(flight, n);
	displayFlight(flight, n);
	highestFlight(flight,n);
	char* code=new char[6];
	cout << "Nhap chuyen bay muon tim: ";
	cin.getline(code,6);
	searchFlight(flight, n, code);
	Date* startday = new Date;
	Date* endday = new Date;
	Time* starttime = new Time;
	Time* endtime = new Time;
	cout << "Nhap ngay bat dau: ";
	cin >> startday->day >> startday->month >> startday->year;
	cout << endl;
	cout << "Nhap gio bat dau: ";
	cin >> starttime->hours >> starttime->minutes;
	cout << endl;
	cout << "Nhap ngay ket thuc: ";
	cin >> endday->day >> endday->month >> endday->year;
	cout << endl;
	cout << "Nhap gio ket thuc: ";
	cin >> endtime->hours >> endtime->minutes;
	cout << endl;
	filterFlight(flight, n, startday, endday, starttime, endtime);
	for (int i = 0; i < n; i++)
		freeFlight(flight[i]);
	delete[] flight;
	delete[] code;
	delete startday;
	delete endday;
	delete starttime;
	delete endtime;
	return 0;
}