#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	vector<int> wait_times;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		wait_times.push_back(a);
	}

	//시간이 작은 순서대로 정렬
	sort(wait_times.begin(), wait_times.end());

	//시간의 누적합
	int sum = wait_times[0];
	int answer = wait_times[0];
	for (int i = 1 ; i < N; i++) {
		sum += wait_times[i];
		answer += sum;
	}

	cout << answer;

}

//ATM 1대
//사람 1~N
// i번사람이 인출하는데 걸리는 시간 Pi

//시간이 최소인 순서대로 진행하면 된다?

//1 2 3 4 5
//1 : 1
//2 : 3
//3 : 6 
//4 : 10
//5 : 15
//


