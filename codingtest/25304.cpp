#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X, N;
	int result=0;

	cin >> X >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		result += a * b;
	}

	if (X == result) { cout << "Yes"; }
	else { cout << "No"; }

}