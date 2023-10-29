#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		numbers.push_back(a);
	}

	int max_ = numbers[0];

	vector<int> answers;
	answers.push_back(max_);

	for (int i = 1; i < n; i++) {
		max_ = max(max_ + numbers[i], numbers[i]);
		answers.push_back(max_);
	}

	sort(answers.begin(), answers.end(), greater<>());

	cout << answers[0];
	
}

//주어지는 수들은 -1000 이상 1000이하
//완전 탐색 - 길이에 따라 N까지의 부분 수열을 모두 탐색한다.
//동적 계획법
// 0번째부터 시작해서, i번째 요소를 오른쪽 끝으로 "무조건"포함하는 수열로 경우의 수를 완전히 나눈다.
//1. 0번째 요소를 오른쪽 끝 -> 그냥 0번째 요소가 최대값
//2. 1번째 요소를 오른쪽 끝 -> 0번째 요소 까지의 최대값 + 1번째 요소 or 1번째 요소 only
//3. 2번째 요소를 오른쪽 끝 -> 2번과정 까지의 최대값 + 2번째요소 or 2번째 요소 only
//...
//...마지막 요소를 오른쪽 끝 -> 전 과정까지의 최대값 + 