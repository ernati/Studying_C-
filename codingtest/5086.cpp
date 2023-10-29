#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;

	while (true) {
		cin >> a >> b;

		if (a == 0 && b == 0) {
			break;
		}

		if (a > b && a % b == 0) { cout << "multiple\n"; }

		else if (a < b && b % a == 0) { cout << "factor\n"; }

		else cout << "neither\n";
	}

}

 

