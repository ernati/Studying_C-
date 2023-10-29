#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<int> numbers;

	int a, b, c;
	cin >> a >> b >> c;

	numbers.push_back(a);
	numbers.push_back(b);
	numbers.push_back(c);

	sort(numbers.begin(), numbers.end());

	int answer;
	int nmb;

	if (numbers[0] != numbers[1]) {
		if (numbers[1] == numbers[2]) {
			nmb = numbers[1];
			answer = 2;
		}
		else { // 두번째와 세번째가 달라 -> 셋 다 달라
			nmb = numbers[2];
			answer = 3;
		}
	}

	else { // 첫번째와 두번째가 같아
		if (numbers[1] == numbers[2]) { // 다 같아
			nmb = numbers[0];
			answer = 1;
		}
		else { //두번째와 세번째가 달라 -> 첫과 둘만 같아
			nmb = numbers[0];
			answer = 2;
		}
	}

	int result;

	switch (answer) {
	case 1:
		result = 10000 + 1000 * nmb;
		break;

	case 2:
		result = 1000 + 100 * nmb;
		break;
	case 3:
		result = 100 * nmb;
		break;
	};

	cout << result;
}