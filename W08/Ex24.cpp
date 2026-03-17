#include <iostream>
using namespace std;

struct Candidate
{
	char* ID;
	char* Name;
	double* Math;
	double* Physics;
	double* Chemistry;
	double* Total;
};
void inputCandidates(Candidate& c)
{
	c.ID = new char[6];
	c.Name = new char[31];
	c.Math = new double;
	c.Physics = new double;
	c.Chemistry = new double;
	c.Total = new double;
	cout << "Nhap ID sinh vien: ";
	cin.getline(c.ID, 6);
	cout << endl;
	cout << "Nhap ho va ten sinh vien: ";
	cin.getline(c.Name, 31);
	cout << endl;
	cout << "Nhap diem toan sinh vien: ";
	cin >> *c.Math;
	cout << endl;
	cout << "Nhap diem Ly sinh vien: ";
	cin >> *c.Physics;
	cout << endl;
	cout << "Nhap diem Hoa sinh vien: ";
	cin >> *c.Chemistry;
	cin.ignore();
	*c.Total = *c.Math + *c.Chemistry + *c.Physics;
}
void inputMultipleCandidate(Candidate* c, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Nhap sinh vien thu " << i + 1 << endl;
		inputCandidates(c[i]);
	}
}
void outputCandidate(Candidate* c, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Sinh vien thu " << i + 1<<endl;
		cout << "ID sinh vien: " << c[i].ID << endl;
		cout << "Ten sinh vien: " << c[i].Name << endl;
		cout << "Diem toan sinh vien: " << *c[i].Math << endl;
		cout << "Diem ly sinh vien: " << *c[i].Physics << endl;
		cout << "Diem hoa sinh vien: " << *c[i].Chemistry << endl;
		cout << "Tong diem sinh vien: " << *c[i].Total << endl;
	}
}
bool passed(double total, double math, double physics, double chemistry)
{
	if (total < 15)
		return false;
	else if (math == 0 || physics == 0 || chemistry == 0)
		return false;
	return true;
}
void passedCandidate(Candidate* c, int n)
{
	cout << endl;
	cout << "Sinh vien tot nghiep: ";
	for (int i = 0; i < n; i++)
	{
		if (passed(*c[i].Total, *c[i].Math, *c[i].Physics, *c[i].Chemistry))
		{
			cout << "ID sinh vien: " << c[i].ID << endl;
			cout << "Ten sinh vien: " << c[i].Name << endl;
			cout << "Diem toan sinh vien: " << *c[i].Math << endl;
			cout << "Diem ly sinh vien: " << *c[i].Physics << endl;
			cout << "Diem hoa sinh vien: " << *c[i].Chemistry << endl;
			cout << "Tong diem sinh vien: " << *c[i].Total << endl;
		}
	}
}
void sortCandidate(Candidate* c, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (*c[j].Total < *c[j + 1].Total)
			{
				Candidate temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
}
void freeCandidate(Candidate& c)
{
	delete[] c.ID;
	delete[] c.Name;
	delete c.Math;
	delete c.Physics;
	delete c.Chemistry;
	delete c.Total;
}
int main()
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	Candidate* c = new Candidate[n];
	inputMultipleCandidate(c, n);
	outputCandidate(c, n);
	cout << endl;
	passedCandidate(c, n);
	sortCandidate(c, n);
	cout << endl;
	cout << "Sau khi sap xep: " << endl;
	outputCandidate(c, n);
	for (int i = 0; i < n; i++)
		freeCandidate(c[i]);
	delete[] c;
	return 0;
}