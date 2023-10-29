#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> coins;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coins.push_back(a);
	}

	int result = 0;

	for (int i = N-1; i>=0 ; i--) {
		//1. 만약 남은 금액이 현재 사용할 동전 금액보다 작다 -> continue
		if (K < coins[i]) continue;
		else {
			//2. coin의 수를 더한다.
			result += K / coins[i];

			//3. 금액을 update한다.
			K %= coins[i];
		}
	}

	cout  << result;
}

//동전의 종류 수 N -> 각 동전의 가치도 존재
// 만들어야하는 값 K
//
// 개수의 최솟값 -> 동전의 액수가 큰 동전부터 우선적으로 넣는다.
//10 50 100 500
// 18290
// 500원부터 -> 금액 / 500 -> 동전 수
// 금액%500 -> 금액 update 
// ..그 다음 남은 금액

