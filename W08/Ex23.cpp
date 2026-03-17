#include <iostream>
using namespace std;

struct Employee
{
	char* ID;
	char* Name;
	double* Salary;
};
void inputEmployee(Employee& e)
{
	e.ID = new char[6];
	e.Name = new char[31];
	e.Salary = new double;
	cout << "Nhap ID nhan vien: ";
	cin.getline(e.ID,6);
	cout << endl;
	cout << "Nhap ten nhan vien: ";
	cin.getline(e.Name,31);
	cout << endl;
	cout << "Nhap luong nhan vien: ";
	cin >> *e.Salary;
	cin.ignore();
}
void inputMultipleEmployee(Employee* e, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Nhap nhan vien thu: " << i + 1 << endl;
		inputEmployee(e[i]);
	}
}
void outputEmployee(Employee* e, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Nhan vien thu " << i + 1 << ":"<<endl;
		cout << "ID nhan vien la: " << e[i].ID<<endl;
		cout << "Ten nhan vien la: " << e[i].Name << endl;
		cout << "Luong nhan vien la: " << *e[i].Salary << endl;
	}
}
void highestSalary(Employee* e, int n)
{
	double max = *e[0].Salary;
	char* nametemp = e[0].Name;
	char* IDtemp = e[0].ID;
	for (int i = 0; i < n; i++)
	{
		if (*e[i].Salary > max)
		{
			max = *e[i].Salary;
			nametemp = e[i].Name;
			IDtemp = e[i].ID;
		}
	}
	cout << "Nhan vien co luong cao nhat la: "<<endl;
	cout << "ID nhan vien: " << IDtemp << endl;
	cout << "Ten nhan vien: " << nametemp << endl;
	cout << "Luong nhan vien: " << max << endl;
}
void totalSalary(Employee* e, int n)
{
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		total += *e[i].Salary;
	}
	cout << "Tong luong nhan vien la: " << total;
}
void freeEmployee(Employee& e)
{
	delete[] e.ID;
	delete[] e.Name;
	delete e.Salary;
}
void sortArray(Employee* e, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (e[j].Salary > e[j + 1].Salary)
			{
				Employee temp = e[j];
				e[j] = e[j + 1];
				e[j + 1] = temp;
			}

		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cin.ignore();
	Employee* e = new Employee[n];
	inputMultipleEmployee(e, n);
	outputEmployee(e, n);
	cout << endl;
	highestSalary(e, n);
	cout << endl;
	totalSalary(e, n);
	sortArray(e, n);
	outputEmployee(e, n);
	for (int i = 0; i < n; i++)
	{
		freeEmployee(e[i]);
	}
	delete[] e;
}