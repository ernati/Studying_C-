#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int max = 2 * N - 1;

	for (int i = 1; i <= N-1; i++) {

		//빈칸을 N-i개 출력
		for (int j = 0; j < N-i; j++) {
			cout << " ";
		}

		//병를 2*i-1개 출력
		for (int j = 0; j < 2*i -1; j++) {
			cout << "*";
		}

		cout << "\n";
	}

	for (int i = 0; i < max; i++) {
		cout << "*";
	}

	cout << "\n";

	for (int i = N - 1; i >= 1; i--) {
		//빈칸을 N-i개 출력
		for (int j = 0; j < N - i; j++) {
			cout << " ";
		}

		//병를 2*i-1개 출력
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}

		cout << "\n";
	}



	

	
}

// 입력 N
// k = 1~N -> 2*k-1개의 별이 찍힘. k==N일 때 2*N-1개의 별이 최댓값
// k = N+1 ~ 2*N-1 -> 역순
// N=1 --> N-1 빈칸, 1 별찍기, N-1 빈칸
//N=2 --> N-2 빈칸, 별찍기, N-2 빈칸 --> 2N-4 + 별찍기 = 2N-1