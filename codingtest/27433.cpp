#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

long long factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}

	else {
		return n * factorial(n - 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	cout << factorial(N);
	
}




