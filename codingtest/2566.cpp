#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector< vector<int> > A;

	//초기화 및 원소 삽입
	for (int i = 0; i < 9; i++) {
		vector<int> tmp;
		A.push_back(tmp);
		for (int j = 0; j < 9; j++) {
			int tmp_num;
			cin >> tmp_num;

			A[i].push_back(tmp_num);
		}
	}

	int idx_x = 0;
	int idx_y = 0;
	int max = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] > max) {
				max = A[i][j];
				idx_x = i;
				idx_y = j;
			}
		}
	}

	cout << max << "\n" << idx_x+1 << " " << idx_y+1;
}