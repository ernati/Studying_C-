#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

bool compare(pair<long long, long long>& a, pair<long long, long long>& b) {
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;

	vector<long long> dist;
	vector<pair<long long,long long>> price;

	//dist 받기
	for (long long i = 0; i < N - 1; i++) {
		long long a;
		cin >> a;
		dist.push_back(a);
	}

	//price 받기
	for (long long i = 0; i < N; i++) {
		long long b;
		cin >> b;
		price.push_back( make_pair( i , b ) ); //i번째 도시의 기름 가격은 b 
	}

	//price를 가격 순으로 정렬
	sort(price.begin(), price.end(), compare);

	//최종 비용
	long long answer = 0;
	long long cheapest_city_idx;
	long long last_city_idx = N - 1;

	while (last_city_idx > 0) {

		long long min = 1000000000;
		//1. price를 훑어서, last_city_idx보다 작은 index 중 가장 작은 가격 및 인덱스를 구한다.
		for (long long i = 0; i < N; i++) {
			if (price[i].first < last_city_idx && price[i].second < min) {
				cheapest_city_idx = price[i].first;
				min = price[i].second;
			}
		}

		//2. 그 인덱스로부터, last_city_idx 까지의 거리만큼의 가격을 더해준다.
		for (long long i = cheapest_city_idx; i < last_city_idx; i++) {
			answer += min * dist[i];
		}

		//3. last_city_idx를 update해준다.
		last_city_idx = cheapest_city_idx;
	}

	cout << answer;
	
}

// 첫번째 줄 : N -> 도시의 개수
// 두번째 줄, 도로의 길이
//세번째 줄, 각 도시의 기름 비용

//맨 오른쪽에서부터 계산하면 어떨까
//전체에서 가격이 가장 싼 도시 부터 끝가지의 거리를 모두 그 도시 가격으로 사.
//그리고 그 도시 전에 있는 가격 중 가장 싼 도시부터 끝까지의 거리를 모두 그 도시 가격으로 사.

//1. 도로의 index와 가격을 묶는다.
//2. 가장 싼 가격을 찾는다.
//3. 그 싼 가격의 도시 위치 부터 끝까지의 거리를 모두 그 도시 가격으로 산다.
//4. 도착 index를 방금 찾은 가장 싼 가격의 도시로 update
//5. 그 다음 싼 가격을 찾는다 ... 반복

//예시
// 5 --2-- 2 --3-- 4 --1-- 1
// 1. last_city_idx = 3 , cheapest_city_idx =  1, min = 2
// answer = answer + 