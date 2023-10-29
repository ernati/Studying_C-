#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	int Quarter = 0;
	int Dime = 0;
	int Nickel = 0;
	int Penny = 0;

	for (int i = 0; i < T; i++) {
		int C; cin >> C;

		if (C >= 25) {
			Quarter = C / 25;
			C = C % 25;
		}

		if (C >= 10) {
			Dime = C / 10;
			C = C % 10;
		}
		if (C >= 5) {
			Nickel = C / 5;
			C = C % 5;
		}

		Penny = C;
		
		cout << Quarter<< " " << Dime << " " << Nickel<< " " << Penny << "\n";

		Quarter = 0;
		Dime = 0;
		Nickel = 0;
		Penny = 0;
	}

	

}

//쿼터 : 25 , 다임 : 10, 니켈 : 5, 페니 : 1
// 그냥 큰거부터 하면 안되나?


