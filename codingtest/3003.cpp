#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int king, queen, look, bishop, knight, pawn;

	cin >> king >> queen >> look >> bishop >> knight >> pawn;

	cout << 1 - king << " ";
	cout << 1 - queen << " ";
	cout << 2 - look << " ";
	cout << 2 - bishop << " ";
	cout << 2 - knight << " ";
	cout << 8 - pawn << " ";

	
}

//16개의 피스
// 킹 1개, 퀸 1개, 비숍 2개, 나이트 2개, 폰 8개