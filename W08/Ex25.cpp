#include <iostream>
using namespace std;

struct Thesis
{
	char* code;
	char* title;
	char* studentname;
	char* supervisorname;
	short* year;
};
void inputThesis(Thesis& t)
{
	t.code = new char[11];
	t.title = new char[101];
	t.studentname = new char[31];
	t.supervisorname = new char[31];
	t.year = new short;
	cout << "Nhap code: ";
	cin.getline(t.code, 11);
	cout << endl;
	cout << "Nhap tieu de: ";
	cin.getline(t.title, 101);
	cout << endl;
	cout << "Nhap ten sinh vien: ";
	cin.getline(t.studentname, 31);
	cout << endl;
	cout << "Nhap ten giang vien: ";
	cin.getline(t.supervisorname, 31);
	cout << endl;
	cout << "Nhap nam hoan thanh: ";
	cin >> *t.year;
	cin.ignore();
}
void inputMultipleThesis(Thesis* t, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Luan van thu: " << i + 1 << endl;
		inputThesis(t[i]);
	}
}
void outputThesis(Thesis* t, int n)
{
	cout << "Danh sach luan van: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Luan van thu " << i + 1 << endl;
		cout << "Ma luan van: " << t[i].code << endl;
		cout << "Tieu de luan van: " << t[i].title << endl;
		cout << "Ten sinh vien: " << t[i].studentname << endl;
		cout << "Ten giang vien: " << t[i].supervisorname << endl;
		cout << "Nam hoan thanh: " << *t[i].year << endl;
	}
}
int size(char* s, int count)
{
	if (s[count] == '\0')
		return count;
	count += 1;
	return size(s, count);
}
bool sortFName(char* s1, char* s2)
{
	int s1size = size(s1, 0);
	int s2size = size(s2, 0);
	int index1=0;
	int index2=0;
	for (int i = s1size - 1; i >= 0; i--)
	{
		if (s1[i] == ' ')
		{
			index1 = i + 1;
			break;
		}

	}
	for (int i = s2size - 1; i >= 0; i--)
	{
		if (s2[i] == ' ')
		{
			index2 = i + 1;
			break;
		}
	}
	for (int i = index1, j = index2; i < s1size&& j < s2size; i++, j++)
	{
		if (s1[i] < s2[j])
			return true;
		else if (s1[i] > s2[j])
			return false;
	}
	return true;
}
void sortedThesis(Thesis* t, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (sortFName(t[j].studentname, t[j + 1].studentname))
			{
				Thesis temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}
void mostThesis(Thesis* t, int n)
{
	short year = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		short tempyear = *t[i].year;
		int tempcount = 0;
		for (int j = 0; j < n; j++)
		{
			if (*t[j].year == tempyear)
				tempcount++;
		}
		if (tempcount > count)
		{
			count = tempcount;
			year = tempyear;
		}
	}
	if (count > 1)
	{
		cout << "Nam co nhieu luan van nhat la nam: " << year << " voi " << count << " luan van";
	}
	else
		cout << "Cac nam deu co so luong luan van bang nhau" << endl;
}
void recentlyThesis(Thesis* t, int n)
{
	short maxyear = 0;
	for (int i = 0; i < n; i++)
	{
		if (*t[i].year > maxyear)
			maxyear = *t[i].year;
	}
	cout << "Luan van gan day nhat: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (*t[i].year == maxyear)
		{
			cout << "Ma luan van: " << t[i].code << endl;
			cout << "Tieu de luan van: " << t[i].title << endl;
			cout << "Ten sinh vien: " << t[i].studentname << endl;
			cout << "Ten giang vien: " << t[i].supervisorname << endl;
			cout << "Nam hoan thanh: " << *t[i].year << endl;
		}
	}
}
void freeThesis(Thesis& t)
{
	delete[] t.code;
	delete[] t.title;
	delete[] t.studentname;
	delete[] t.supervisorname;
	delete t.year;

}
int main()
{
	int n;
	cout << "Nhap so luong luan van: ";
	cin >> n;
	cin.ignore();
	Thesis* t = new Thesis[n];
	inputMultipleThesis(t, n);
	outputThesis(t, n);
	sortedThesis(t, n);
	cout << "Sau khi sap xep: ";
	outputThesis(t, n);
	mostThesis(t, n);
	cout << endl;
	recentlyThesis(t, n);
	for (int i = 0; i < n; i++)
		freeThesis(t[i]);
	delete[] t;
	return 0;
}