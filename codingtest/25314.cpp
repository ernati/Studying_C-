#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	N /= 4;

	string answer = "";

	string temp = "long ";

	for (int i = 0; i < N; i++) {
		answer += temp;
	}

	answer += "int";

	cout << answer;
}