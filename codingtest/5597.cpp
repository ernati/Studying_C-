#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> check;

	for (int i = 0; i < 31; i++) { // 0번은 사용하지 않음
		check.push_back(false);
	}

	for (int i{ 0 }; i < 28; i++) {
		int a;
		cin >> a;

		check[a] = true;
	}

	for (int i{ 1 }; i <= 30; i++) {
		if (!check[i]) { cout << i << "\n"; }
	}

}