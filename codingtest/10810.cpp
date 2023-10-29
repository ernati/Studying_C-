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
		baskets.push_back(0);
	}

	for (int i{ 0 }; i < M; i++) {
		int j, k, l;
		cin >> j >> k >> l;
		for (int s{ j }; s <= k; s++) {
			baskets[s] = l;
		}
	}

	for (int i{ 1 }; i < N+1; i++) {
		cout << baskets[i] << " ";
	}


}


//바구니가 N개, 1번부터 N번까지 번호
//1번부터 N번까지 번호가 적힌 공을 매우 많이 -> 무제한
//1번 바구니에는 공이 없고, 바구니에는 공을 1개만 넣을 수 있다.

//M번 공을 넣는다.
//한 번 공을 넣을 때, 바구니 범위를 정하고, 정한 바구니에 모두 같은 번호가 적힌 공을 넣는다.
//바구니에 공이 들어가 있다면, 들어있는 공을 빼고, 새로 공을 넣는다.

//