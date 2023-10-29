#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector< vector<int> > A, B;

	int N, M;
	cin >> N >> M;

	//A 초기화 및 원소 삽입
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		A.push_back(tmp);
		for (int j = 0; j < M; j++) {
			int tmp_num;
			cin >> tmp_num;
			A[i].push_back(tmp_num);
		}
	}

	//B 초기화 및 원소 삽입
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		B.push_back(tmp);
		for (int j = 0; j < M; j++) {
			int tmp_num;
			cin >> tmp_num;
			B[i].push_back(tmp_num);
		}
	}

	//A+B
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] += B[i][j];
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}


}

//