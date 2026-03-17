#include <iostream>
using namespace std;

struct Data {
	int day;
	int month;
	int year;
};
struct Player {
	char* ID;
	char* Name;
	Data* Birth;
};
void inputPlayer(Player& p)
{
	p.ID = new char[11];
	p.Name = new char[31];
	p.Birth = new Data;
	cout << "Nhap ID nguoi choi: ";
	cin.getline(p.ID,11);
	cout << endl;
	cout << "Nhap ten nguoi choi: ";
	cin.getline(p.Name,31);
	cout << endl;
	cout << "Nhap ngay thang nam sinh nguoi choi: ";
	cin >> p.Birth->day >> p.Birth->month >> p.Birth->year;
	cin.ignore();
	cout << endl;
}
void inputMutiplePlayers(Player* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nguoi choi thu " << i + 1 << endl;;
		inputPlayer(p[i]);
	}
}
void outputPlayers(Player* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "ID nguoi choi thu " << i + 1 << " la: " << p[i].ID << endl;
		cout << "Ten nguoi choi thu " << i + 1 << " la: " << p[i].Name << endl;
		cout << "Ngay sinh nguoi choi thu " << i + 1 << " la: " << p[i].Birth->day << "/" << p[i].Birth->month << "/" << p[i].Birth->year << endl;
	}
}
void youngestPlayer(Player* p, int n)
{
	int minyear = 10000;
	for (int i = 0; i < n; i++)
	{
		if (p[i].Birth->year < minyear)
			minyear = p[i].Birth->year;
	}
	int minmonth = 13;
	for (int i = 0; i < n; i++)
	{
		if (p[i].Birth->year == minyear && p[i].Birth->month < minmonth)
			minmonth = p[i].Birth->month;
	}
	int minday = 32;
	for (int i = 0; i < n; i++)
	{
		if (p[i].Birth->year == minyear && p[i].Birth->month == minmonth && p[i].Birth->day < minday)
			minday = p[i].Birth->day;
	}
	cout << "Nguoi choi nho nhat la: ";
	for (int i = 0; i < n; i++)
	{
		if (p[i].Birth->year == minyear && p[i].Birth->month == minmonth && p[i].Birth->day == minday)
		{
			cout << endl;
			cout << "ID nguoi choi thu " << i + 1 << " la: " << p[i].ID << endl;
			cout << "Ten nguoi choi thu " << i + 1 << " la: " << p[i].Name << endl;
			cout << "Ngay sinh nguoi choi thu " << i + 1 << " la: " << p[i].Birth->day << "/" << p[i].Birth->month << "/" << p[i].Birth->year << endl;
		}
	}
}
void sortedPlayer(Player* p, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].Birth->year < p[j + 1].Birth->year)
			{
				Player temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].Birth->year == p[j + 1].Birth->year && p[j].Birth->month < p[j + 1].Birth->month)
			{
				Player temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].Birth->year == p[j + 1].Birth->year && p[j].Birth->month == p[j + 1].Birth->month && p[j].Birth->day < p[j + 1].Birth->day)
			{
				Player temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
void freePlayer(Player& p)
{
	delete[] p.ID;
	delete[] p.Name;
	delete p.Birth;
}
int main()
{
	int n;
	cout << "Nhap so luong nguoi choi: ";
	cin >> n;
	cin.ignore();
	Player* p = new Player[n];
	inputMutiplePlayers(p, n);
	outputPlayers(p, n);
	youngestPlayer(p, n);
	cout << "Sau khi sap xep: ";
	sortedPlayer(p, n);
	outputPlayers(p, n);
	for (int i = 0; i < n; i++)
		freePlayer(p[i]);
	delete[] p;
}