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

	int N, K;
	cin >> N >> K;

	vector<int> factors;

	for (int i = 1; i <= static_cast<int>(sqrt(N)); i++) {
		if (N % i == 0) {
			factors.push_back(N/i);
			if( N/i != i ) factors.push_back(i);
		}
	}

	sort(factors.begin(), factors.end());

	if (factors.size() < K) {
		cout << 0;
	}

	else cout << factors[K-1];

}

 

