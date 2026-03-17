#include <iostream>
#include <cmath>
using namespace std;

double Mean(int a[], int n)
{
	double chia = 1.0 / n;
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i];
	}
	double mean = tong * chia;
	return mean;
}
double Variance(int a[], int n)
{
	double chia = 1.0 / n;
	double mean = Mean(a, n);
	double tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += pow((a[i] - mean), 2);
	}
	double variance = tong * chia;
	return variance;
}
double StandardDeviation(int a[], int n)
{
	double variance = Variance(a, n);
	double standarddeviation = sqrt(variance);
	return standarddeviation;
}

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	double mean = Mean(a, n);
	double variance = Variance(a, n);
	double standarddeviation = StandardDeviation(a, n);
	cout << "Mean = " << mean << endl;
	cout << "Variance = " << variance << endl;
	cout << "Std. deviation =  " << standarddeviation << endl;
	return 0;

}