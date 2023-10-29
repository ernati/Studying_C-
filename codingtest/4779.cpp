#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void make_cantor(vector<char>& chars, int N, int left, int right) {
	/*cout << "N is " << N << "\n";
	cout << "left is " << left << "\n";
	cout << "right is " << right << "\n";*/

	//1. 종료 조건
	if (N==0) { // N==0
		chars[0] = '-';
		return;
	}
	else if (N==1) // 
	{
		chars[left] = '-';
		chars[right] = '-';
		return;
	}

	else {
		int all = pow(3, N - 1);
		make_cantor(chars, N - 1, left, left+all-1);
		make_cantor(chars, N - 1, left + 2*all, left + 3*all- 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<char> chars;

	while (1) {
		cin >> N;
		if (cin.eof()) break;

		chars.clear();
		for (int i = 0; i < pow(3, N); i++) {
			chars.push_back(' ');
		}

		make_cantor(chars, N, 0, chars.size() - 1);

		for (int i = 0; i < chars.size(); i++) {
			cout << chars[i] << " ";
		}
		cout << "\n";
	}

}

//N=k -> 3^k의 dash부터 시작, 점점 없애나감.

// 0 27 
// 3등분을 함.
//가운데를 버림.
//종료 조건에서 vector에 '-'를 넣자.
//0 27 -> 0~8 , 18~26
//0~8 -> 0~2, 6~8
//0~2 -> 0~2/3



//
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//void cantor(int n) {
//	int size = pow(3, n - 1);
//
//	// N = 0 인 경우 "-" 출력
//	if (n == 0) {
//		cout << "-";
//		return;
//	}
//
//	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
//	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
//	cantor(n - 1);
//	for (int i = 0; i < size; i++) {
//		cout << " ";
//	}
//	cantor(n - 1);
//
//}
//
//int main() {
//	int N;
//
//	while (cin >> N) {
//		cantor(N);
//		cout << "\n";
//	}
//
//	return 0;
//}