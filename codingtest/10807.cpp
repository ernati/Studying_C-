#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> tmp;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		tmp.push_back(a);
	}

	int v;
	cin >> v;

	int answer = 0;

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == v) { answer++; }
	}

	cout << answer;
}