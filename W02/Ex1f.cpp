#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	double tong = 0;
	for (float i = 1; i <= n; i++) {
		tong += i / (i + 1);
	}
	cout << tong;
	return 0;
}