#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>

using namespace std;

int sumDist(vector<int>& paper, int a, int b) {
	int result = 0;
	for (int i = a; i <= b; i++) {
		result += paper[i];
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> papers;	
	vector<vector<int>> memo;

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int answer = 0;
		//papers clear
		papers.clear();

		//papers 초기화
		int K; cin >> K;
		for (int j = 0; j < K; j++) {
			int tmp;
			cin >> tmp;
			papers.push_back(tmp);
		}

		//memo초기화
		memo.clear();
		for (int i = 0; i < K; i++) {
			vector<int> tmp2;
			for (int i = 0; i < K; i++) {
				tmp2.push_back(0);
			}
			memo.push_back(tmp2);
		}

		//초기값
		for (int i = 0; i < K; i++) {
			memo[i][i] = 0;
		}

		// a+b의 최솟값은 a+b
		for (int i = 0; i < K - 1; i++) {
			memo[i][i + 1] = papers[i] + papers[i + 1];
		}

		//점화식 사용 //memo[0][2] , memo[]
		for (int i = 2; i <= papers.size()-1; i++) {
			for (int j = 0; j + i < papers.size(); j++) {
				int min = 50000;
				for (int k = j; k+1 <= j +i; k++) { 
					if (min > memo[j][k] + memo[k + 1][j + i] + sumDist(papers, j, j + i)) {
						min = memo[j][k] + memo[k + 1][j + i] + sumDist(papers, j, j + i);
					}
				}

				memo[j][j + i] = min;
				//cout << "[" << j << " " << j + i << "] -> " << memo[j][j+i] <<"\n";
			}
		}

		cout << memo[0][papers.size() - 1];


		
	}

}

//소설의 각 장들을 2장씩 합쳐서 최종 파일을 만들 때, 가장 최소비용으로.
//이게 근데 보니까, 더할 때, 파일의 비용이 들어가.
//그리고 그 파일의 비용은 지속적으로 누적이돼.
//그러니까, 작은거부터 하면 돼.

//근데 이제 하나의 파일에다가 하나를 더하는 것도 안돼.
//왜냐면 그 파일의 크기가 커질수록 누적되는 비용도 높아지니까.
//그러면 모든 시행에서 항상 이미 만들어진 종이 중, 가장 작은 두 종이를 합치면 돼.
//priority queue

//아 근데 이게, 연속적인 page다.
//순서가 흐트러지면 안돼.
//예를 들어서 C1, C2, C3, C4니까
// C1+C3같은 작업은 불가능해...
 
//그러면, 전체를 훑으면서, 인접한 2개 중 가장 값이 작은 쌍을 찾아야 함.
//그리고 두 페이지를 합치면, 벡터의 원소들을 한칸씩 밀어야돼.
//아니야. 답을 찾아버려썽.

//만약 paper수가 짝수야 -> 처음부터 연속된거 끼리 다 더해
//paper수가 홀수야 -> 제일 큰 종이 빼고 연속된걸 다 더해. 미쳤다 도라따

//21 3 4 5 35
//(a+b+c)의 최소 = ( a+b + a+b+c ) or ( b+c + a+b+c )
//(a+b+c+d)의 최소 = ( a+b + c+ d + a+b+c+d ) or ( a+b+c + a+b+c+d ) or ( b+c+d + a+b+c+d )
//-> dp[i][j] = min( dp[i][k] + dp[k+1][j] + price[i]+price[i+1]+...+price[j] )

//관계식 
//DP란 관계식이다.

//수가 4개
//40 30 30 50
//memo[0][0] = 0, memo[1][1] = 0, memo[2][2] = 0, memo[3][3] = 0
//memo[0][1] = 70, memo[1][2] = 60, memo[2][3] = 80
//memo[0][2] = min( memo[0][1] + memo[1][2] + ~ ) ,  memo[1][3] = min( memo[1][2] + memo[2][3] + ~ )
//memo[0][3] = ( memo[0][1] + memo[2][3] + ~ )  or memo[0][2] + +memo[3][3] + ~

//수가 총 8개
//0,2 1,3 2,4 ... 5,7
//0,3 1,4 2,5 ...
//0,4 1,5 3,6 ... 
//...
//0,7


