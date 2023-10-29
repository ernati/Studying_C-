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

	long long N;
	vector<long long> factors;
	long long sum;

	while (true) {
		cin >> N;

		if (N == -1) { break; }
		factors.clear();

		for (int i = 1; i <= static_cast<int>(sqrt(N)); i++) {
			if (N % i == 0) {
				factors.push_back(i);
				if (N / i != i) factors.push_back(N/i);
			}
		}

		sort(factors.begin(), factors.end());

		sum = 0;

		/*cout << "=========================================\n";

		for (int i = 0; i < factors.size(); i++) {
			cout << factors[i] << " ";
		} cout << "\n";

		cout << "=========================================\n";*/

		for (int i = 0; i < factors.size()-1; i++) {
			sum += factors[i];
		}

		//cout << "sum is " << sum;
		//cout << "\n=========================================\n";

		if (sum == N) {
			cout << N << " = ";
			for (int i = 0; i < factors.size()-1; i++) {
				cout << factors[i];
				if (i < factors.size() - 2) {
					cout << " + ";
				}
			}
			cout << "\n";
		}
		else {
			cout << N << " is NOT perfect.\n";
		}
	}


	

}

 

