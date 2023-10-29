#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long A, B, C;
	cin >> A >> B >> C;

	vector<int> binary_num;

	while (B > 1) {
		binary_num.push_back(B % 2);
		B /= 2;
	}

	binary_num.push_back(B);

	long long answer = 1;
	long long tool = 1;

	for (int i = 0; i < binary_num.size(); i++) {
		// i == 0 -> tool = A
		if (i == 0) { 
			tool = A; 
			tool %= C;
			if (binary_num[i] == 1) {
				answer *= tool;
				answer %= C;
			}
		}
		else {
			tool *= tool;
			tool %= C;
			if (binary_num[i] == 1) {
				answer *= tool;
				answer %= C;
			}
		}
	}

	cout << answer;
}

//82 / 2 = 41 ... 0
//41 / 2 = 20 ... 1
//20 / 2 = 10 ...0
//10 / 2 = 5 ...0
//5 / 2 = 2 ... 1
// 2 / 2 = 1 ...0
// 1
//1010010 = 64 + 16 + 2