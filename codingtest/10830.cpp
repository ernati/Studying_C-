#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

//N*N 두 행렬을 곱한다. 답 행렬[i][j] = 
void matmul(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int N) {
	vector<vector<int>> result;

	//result 초기화
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			tmp.push_back(0);
		}
		result.push_back(tmp);
	}

	//matmul
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	//copy matmul to mat1
	copy(result.begin(), result.end(), mat1.begin());
}

void moduler_1000(vector<vector<int>>& mat1) {
	for (int i = 0; i < mat1.size(); i++) {
		for (int j = 0; j < mat1.size(); j++) {
			mat1[i][j] %= 1000;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long B;

	cin >> N >> B;

	vector<int> B_binary;
	//이진수로 담기 - 맨 처음 원소부터 참조할것이므로, 그냥 나머지 구하는대로 넣으면 된다.
	while (B > 1) {
		//나머지 담기
		B_binary.push_back(B % 2);

		//B update하기
		B = B / 2;
	}
	//마지막 나머지 넣기
	B_binary.push_back(B);

	//2진수 완성
	//벡터를 이제 훑으면서, 가자.

	vector<vector<int>> answer;
	//answer초기화 - identity matrix로 놓자.
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			tmp.push_back(0);
		}
		answer.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		answer[i][i] = 1;
	}

	//cout << "====================================\n";
	////answer 확인
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << answer[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//cout << "====================================\n";


	vector<vector<int>> tool;
	//tool 초기화
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		tool.push_back(tmp);
	}

	//2진수 훑기
	for (int i = 0; i < B_binary.size(); i++) {
		//일단 항상 제곱은 하자.
		if(i != 0) {
			//tool 거듭제곱
			matmul(tool, tool, N);
			moduler_1000(tool);

			//2진수 자리값이 1이면, answer에 곱해준다.
			if (B_binary[i] == 1) { 
				matmul(answer, tool, N);
				moduler_1000(answer);
			}
		}

		else { //i==0
			if (B_binary[i] == 0) {
				continue;
			}
			else {
				matmul(answer, tool, N);
			}
		}
	}

	//answer 확인 - 1000 모듈러 연산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
	
}

//B는 long으로
//B가 52야 -> 110100 -> 1자리가 0 : 넘어감 -> 2자리가 1 : 넘어감 -> 4자리가 1 -> 정답에 네제곱을 추가
//52 / 2 = 26 ... 0
//26/2 =13 ...0
//13 / 2 = 6 ... 1
//6 / 2 = 3...0
//3 / 2 = 1...1



