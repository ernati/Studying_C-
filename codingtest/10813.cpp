#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> baskets;
	for (int i{ 0 }; i < N+1; i++) { //0번은 사용하지 않는다.
		baskets.push_back(i);
	}

	for (int i{ 0 }; i < M; i++) {
		int j, k;
		cin >> j >> k;

		int tmp = baskets[j];
		baskets[j] = baskets[k];
		baskets[k] = tmp;
	}

	for (int i{ 1 }; i < N+1; i++) {
		cout << baskets[i] << " ";
	}


}


