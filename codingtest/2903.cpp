#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int answer = 0;
	int one_side_points = 0;
	int middle_points = 0;


	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			one_side_points = 3; middle_points = 2; answer = one_side_points * one_side_points;
		}
		else {
			one_side_points += middle_points;
			middle_points = one_side_points - 1;
			answer = one_side_points * one_side_points;
		}
	}

	cout << answer;
	

}

//N이 1 -> 한번 시행한 것 -> 9
// N이 1 -> 한변에 점 3개 -> 사이칸 2개
//N =2 -> 한 변에  점 5개 -> 사이칸 4개
//N=3 -> 한 변에 점 9개  -> 사이칸 8개
//.. N=k -> 사이칸 2^k개 -> 

