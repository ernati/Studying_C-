#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int cnt;

int recursion(string& s, int l, int r) {
	if (l >= r) {
		cnt++;  
		return 1;
	}
	else if (s[l] != s[r]) {
		cnt++;
		return 0;
	}
	else {
		cnt++;
		return recursion(s, l + 1, r - 1);
	}
}

int isPalindrome(string& s) {
	return recursion(s, 0, s.length() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string S;
		cin >> S;

		cnt = 0;

		cout << isPalindrome(S) << " " << cnt << "\n";
	}

}


//팰린드롬이면 1, 아니면 0
