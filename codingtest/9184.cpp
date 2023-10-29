#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int get_value(vector<vector<vector<int>>>& memo, int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (a > 20 || b > 20 || c > 20) return get_value(memo, 20, 20, 20);

	//이미 알고있는 값이라면, 바로 리턴
	if (memo[a][b][c] != -1) return memo[a][b][c];

	else {

		if (a < b && b < c) {
			return get_value(memo, a, b, c - 1) + get_value(memo, a, b - 1, c - 1) - get_value(memo, a, b - 1, c);
		}

		else {
			return get_value(memo, a - 1, b, c) + get_value(memo, a - 1, b - 1, c) + get_value(memo, a - 1, b, c - 1) - get_value(memo, a - 1, b - 1, c - 1);
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<vector<int>>> memos;

	//초기화
	for (int i = 0; i <= 20; i++) {
		vector<vector<int>> tmp1;
		for (int j = 0; j <= 20; j++) {
			vector<int> tmp2;
			for (int k = 0; k <= 20; k++) {
				tmp2.push_back(-1);
			}
			tmp1.push_back(tmp2);
		}
		memos.push_back(tmp1);
	}

	//일단 기본값들을 채운다.
	memos[0][0][0] = 1;
	memos[0][0][1] = 1; 
	memos[1][0][0] = 1;
	memos[0][1][0] = 1;
	memos[1][1][0] = 1;
	memos[1][0][1] = 1;
	memos[0][1][1] = 1;
	memos[1][1][1] = 2;   // 1,1,1 -> 0,1,1 + 0,0,1 + 0,1,0 - 0,0,0, = 1+ 1+ 1 -1

	//이제 이 값들로 나머지 값들을 채운다. - 어떻게 채우지
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				memos[i][j][k] = get_value(memos,i, j, k); 
			}
		}
	}
	
	while (true) {
		int a, b, c ;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) { break; }
		else {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << get_value(memos, a, b, c) << "\n";
 		}
	}
	
}

// w라는 함수 -> w(a,b,c)
// a,b,c가 모두 0이하 -> 1 리턴
// a,b,c가 모두 20 초과 -> w(20,20,20) 리턴
// a<b<c 일경우 -> w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
//나머지 경우 -> w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
//
//w(3,4,5) -> w(3,4,4) + w(3,3,4) - w(3,3,5)
//w(2,7,4) -> w(1,7,4 + w(1,6,4) + w(1,7,3) - w(1,6,3) )

//a,b,c가 등차수열인 경우는, c하나 줄이고, b랑 c하나 줄인거 더한값에서  b하나 줄인걸 뺌
//나머지 경우는 -> a하나 빼고, a,b 하나 빼고, a,c하나뺀 후에 다 더한다음 a,b,c뺀 걸 뺌.
//결국은 -> a,b,c가 모두 0이되면 끝이야.
//그냥 적어볼까?
//20 * 20 * 20 = 8000경우만 적으면 됨.

//5 1 1 -> 4 1 1 + 1 + 1   = 10
// 4 1 1 -> 3 1 1 + 1 + 1 = 8
//3 1 1 -> 3 + 1 + 1 - 1= 6
// 2 1 1 -> 111 + 1 + 1 - 1 = 3

//1 2 3 -> 1 2 2 + 1 1 2 - 1 1 3 = 

