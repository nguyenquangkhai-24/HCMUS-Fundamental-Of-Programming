#include <iostream>
using namespace std;
 int main() {
	 int n;
	 cin >> n;
	 int giaithua = 1;
	 double tong = 0;
	 for (int i = 1; i <= n; i++) {
		 giaithua *= i;
		 tong += 1.0 / giaithua;
	 }
	 cout << tong;
	return 0;
 }