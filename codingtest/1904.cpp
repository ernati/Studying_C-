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

	long long N;
	cin >> N;

	vector<long long> memo;

	//초기화
	for (int i = 0; i <= N; i++) {
		memo.push_back(0);
	}

	//초기값
	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i <= N; i++) {
		memo[i] = (memo[i - 1]%15746 + memo[i - 2]%15746)%15746;
	}

	cout << memo[N];
}

//나는 1과 00을 갖고 있다.
//N이 주어졌을 때, 만들 수 있는 모든 가짓수
//N=1 -> 1
//N=2 -> 11 00
//N=3 -> 111 001 100
//그냥 맨 처음부터 
//1. 1을 넣는다 -> vector에 1을 넣음 -> 그리고 나머지 N-1개를 채운다.
//2. 00을 넣는다 -> vector에 00을 넣음 ->그리고 나머지 N-2개를 채운다.
//이런식으로 재귀를 때리면 될듯?
//재귀는 터진다!
//즉, 1과 2로 자연수 N을 만드는 경우의 수가 필요한 거잖아?
//문제는 이제 2가 1개여도, 경우의 수가 여러개라는 거지.
//N이라 하자.
// 2가 0개 -> N개의 1 --> nC0 --> 1
//2가 1개 -> 1개의 2, N-2개의 1--> 경우의수는 n-1C1
//2가 2개  -> 2개의 2, N-4개의 1 --> n-2 C 2
//2가 3개 --> 3개의 2, N-6개의 1 --> N-3 C 3
//2가 k개 --> k개의 2, N-2*k 개의 1 --> N-k C k
//...
//2가 n/2개 --> n/2개의 2 --> n/2 C n/2 == 1

// N-k C k == N-k C k ==> (N-k)! / (N-2k)! k! 
//10C4 = 10! / 4! 6! = 10 9 8 7 / 4 3 2 1
//음...근데 N이 100만이라...
//팩토리얼은 터져버려욧.

//다시 돌아가서
//make_binary( N ) = make_binary( N-2 ) + make_binary(N-1) ;

//N=8 -> 8 C 0 + 7 C 1 + 6 C 2 + 5 C 3 + 4C4 = 1 + 7 + 15 + 10 + 1 = 34

//1 1 1 1 1 1 1 1
//00 1 1 1 1 1 1
//00 00 1 1 1 1
//00 00 00 1 1 
//00 00 00 00