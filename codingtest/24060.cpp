#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int save_point = 0;
int K;
int answer_num=-1;

vector<int> merge__(vector<int>& a, vector<int>& b) {
	vector<int> result;

	int i = 0, j = 0;

	while (i < a.size() && j < b.size()) {
		if (a[i] >= b[j]) {
			result.push_back(b[j]);

			j++;

			//save
			save_point++;
			if (save_point == K) {
				answer_num = b[j-1];
			}

			
		}
		else {
			result.push_back(a[i]);
			i++;

			//save
			save_point++;
			if (save_point == K) {
				answer_num = a[i - 1];
			}
		}
	}

	if (i == a.size()) {
		for (int k = j; k < b.size(); k++) {
			result.push_back(b[k]);
			//save
			save_point++;
			if (save_point == K) {
				answer_num = b[k];
			}
		}

		return result;
	}
	else {
		for (int k = i; k < a.size(); k++) {
			result.push_back(a[k]);
			//save
			save_point++;
			if (save_point == K) {
				answer_num = a[k];
			}
		}

		return result;
	}
}

vector<int> merge_sort(vector<int>& numbers, int left, int right) {
	//1. left==right (벡터의 크기가 1) -> 그 값을 리턴 
	if (left == right) { return { numbers[left] }; }
	else {
		int mid = (left + right) / 2;

		return merge__(merge_sort(numbers, left, mid), merge_sort(numbers, mid + 1, right));
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N >> K;

	vector<int> numbers;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	auto answer = merge_sort(numbers, 0, numbers.size() - 1);

	cout << K << " " << save_point << " " << answer_num;
}


//병합정렬
//idx방식으로 구현한다면?
//시작 -> 절반으로 나눔. left,right, left, right
//종료조건이 됨-> 



// #include <iostream>
// #include <vector>
// using namespace std;

// int N, K;
// int cnt = 0;
// int ans = -1;

// // A[p...q]와 A[q+1...r]을 병합하여 A[p...r]을 오름차순 정렬된 상태로 만든다.
// void merge(vector<int>& A, int p, int q, int r)
// {
// 	int i = p, j = q + 1, t = 0;
// 	vector<int> tmp;
// 	while (i <= q && j <= r) {
// 		if (A[i] < A[j])
// 			tmp.push_back(A[i++]);
// 		else
// 			tmp.push_back(A[j++]);
// 		cnt++;
// 		if (cnt == K) // K번째 저장된 수
// 			ans = tmp.back();
// 	}

// 	// 왼쪽 배열 부분이 남은 경우
// 	while (i <= q) {
// 		tmp.push_back(A[i++]);
// 		cnt++;
// 		if (cnt == K) // K번째 저장된 수
// 			ans = tmp.back();
// 	}
// 	// 오른쪽 배열 부분이 남은 경우
// 	while (j <= r) {
// 		tmp.push_back(A[j++]);
// 		cnt++;
// 		if (cnt == K) // K번째 저장된 수
// 			ans = tmp.back();
// 	}

// 	// 결과를 배열 A에 저장
// 	i = p;
// 	while (i <= r)
// 		A[i++] = tmp[t++];
// }

// // p는 분할된 배열의 좌측 끝, r은 우측 끝을 나타낸다.
// void merge_sort(vector<int>& A, int p, int r)
// {
// 	if (p < r) {
// 		int q = (p + r) / 2; // 중간 지점을 찾는다.
// 		merge_sort(A, p, q); // 전반부 정렬
// 		merge_sort(A, q + 1, r); // 후반부 정렬
// 		merge(A, p, q, r); // 병합
// 	}
// }

// int main(void)
// {
// 	cin.tie(NULL);
// 	ios_base::sync_with_stdio(false);

// 	cin >> N >> K;
// 	vector<int> A(N);
// 	for (int i = 0; i < N; i++)
// 		cin >> A[i];
// 	merge_sort(A, 0, N-1);
// 	cout << ans << endl;

// 	return 0;
// }