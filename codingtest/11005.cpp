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

	vector<int> answer;

	int N, B;
	cin >> N >> B;


	while( N>0 ) {
		answer.push_back(N % B);
		N = N / B;
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		int tmp = answer[i];

		if (0 <= tmp && tmp <= 9) { cout << tmp; }
		else { // 10<=tmp<=35
			tmp += 55;
			cout << static_cast<char>(tmp);
		}
	}

}

//'0' : 48 ~ '9' : 57
//'A' : 65 ~ 'Z' : 90
//25384
// 25384 / 3 = 8461 ... 1
// 8461 / 3 = 2820 ... 1
// 2820 /3 = 940 ... 0
// 940 / 3 = 313 ... 1
// 313 / 3 = 104 ... 1
// 104 / 3 = 34 ... 2
// 34 / 3 = 11 ... 1
// 11 / 3 = 3 ... 2
// 3 / 3 = 1 ... 0 
// 1 / 3 = 0 ... 1

//1021211011

//vector에는 1101121201


