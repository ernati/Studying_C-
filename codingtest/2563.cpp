#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	vector<vector<int>> paper;

	//도화지 초기화
	for (int i = 0; i < 100; i++) {
		vector<int> tmp;
		//tmp 채우기
		for (int j = 0; j < 100; j++) {
			tmp.push_back(0);
		}

		paper.push_back(tmp);
	}

	int N; cin >> N; //N : 색종이 수
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				paper[j][k]++;
			}
		}
	}

	int answer = 0;

	//넓이 체크
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] != 0) { answer++; }
		}
	}

	cout << answer;
}

//받은 범위를 1x1 모눈종이로 나눈다 생각하고, 받은 범위만큼 색칠하면 될듯
//주어진 값 : 색종이의 왼쪽 밑 꼭짓점
// 0~100 , 0~100