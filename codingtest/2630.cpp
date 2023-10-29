#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int blue, white;

//주어진 paper의 start_x, start_y칸에서 부터 n길이의 정사각형 내의 종이가 한 색으로만 칠해져있는 지 확인
int paper_check(vector<vector<int>>& paper, int start_x, int start_y, int n) {
	//1. check
	int color;
	for (int i = start_x; i < start_x + n; i++) {
		for (int j = start_y; j < start_y + n; j++) {
			if (i == start_x && j == start_y) { color = paper[i][j]; }
			else {
				if (color != paper[i][j]) return 2;
			}
		}
	}
	//하나의 색으로만 이루어져 있음
	if (color == 0) { return 0; }
	else { return 1; }
}

void check(vector<vector<int>>& paper, int start_x, int start_y, int n) {
	//1. 한 종이로 이루어져있으면, 종이의 수를 더해주고 끝낸다.
	int checking = paper_check(paper, start_x, start_y, n);
	if (checking == 0) { white++; return; }
	else if (checking == 1) { blue++; return;  }
	else { //2. 한 종이로 이루어져있지 않다면, 4등분해서 각각 처리한다.
		int num = n / 2;
		check(paper, start_x, start_y, num);
		check(paper, start_x + num, start_y, num);
		check(paper, start_x, start_y + num, num);
		check(paper, start_x + num, start_y + num, num);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	vector< vector<int> > paper;

	blue = 0;
	white = 0;

	//paper초기화
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a; 
			cin >> a;
			tmp.push_back(a);
		}
		paper.push_back(tmp);
	}


	check(paper, 0, 0, N);

	cout << white << "\n" << blue;
}
//종이를 자를 때,
//전체 종이가 모두 같은색이 아니라면 -> 4개의 종이로 4등분 한다.
//그래서, 각 종이가 모두 같은 색으로 칠해질때까지 자른다.
//혹은, 하나의 정사각형 칸이 되면 끝이다.

//전체를 check한다.
//하나의 색으로 이루어지지 않으면, 4개로 자른 각각의 것에 대해서 다시 똑같은 작업을 수행한다.
//하나의 색으로 이루어져 있다면, 그 색종이 수를 1 증가시킨다.