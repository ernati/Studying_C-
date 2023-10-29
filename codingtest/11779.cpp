#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>

using namespace std;


struct pair3 {
	int start;
	int end;
	int cost;

	pair3(int, int, int);

	bool operator<(const pair3 other) const {
		return this->cost > other.cost;
	}
};

pair3::pair3(int a, int b, int c) {
	start = a;
	end = b;
	cost = c;
}

vector<vector<pair<int, int>>> adj_list;
priority_queue<pair3> pq;
vector<int> dist;
vector<int> route; // a->b : route[b]=a

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//adj_list 초기화
	for (int i = 0; i <= n; i++) {
		vector<pair<int, int>> tmp;
		adj_list.push_back(tmp);
	}

	//adj_list에 넣기
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj_list[a].push_back(make_pair(b, c));
		//adj_list[b].push_back(make_pair(a, c));
	}

	int start_point, end_point;
	cin >> start_point >> end_point;

	//dist 초기화
	for (int i = 0; i <= n; i++) {
		if (i == 0) { dist.push_back(0); }
		else if (i == start_point) { dist.push_back(0); }
		else {
			dist.push_back(200000000);
		}
	}

	//route 초기화
	for (int i = 0; i <= n; i++) {
		route.push_back(0);
	}


	pq.push(pair3(start_point, start_point, 0));

	while (!pq.empty()) {
		//방문
		auto meet = pq.top(); //pair3
		pq.pop();

		//cout << "visit : " << meet.start << "\n";

		//방문할 곳들 중 거리 update를 할 곳만 거리 update하고 큐에 넣기
		for (int i = 0; i < adj_list[meet.start].size(); i++) {
			int will = adj_list[meet.start][i].first;
			if (dist[will] > dist[meet.start] + adj_list[meet.start][i].second) {
				dist[will] = dist[meet.start] + adj_list[meet.start][i].second;
				pq.push(pair3(will, will, dist[will]));

				route[will] = meet.start;


				/*cout << "cost " << adj_list[meet.start][i].second << "\n";
				cout << "dist " << will << " " << dist[will] << "\n";*/
			}
		}
	}

	/*for (int i = 0; i < dist.size(); i++) {
		cout << dist[i] << " ";
	}*/

	cout << dist[end_point] << "\n";
	vector<int> answer;
	int cnt = end_point;

	answer.push_back(cnt);
	//route 를 돌면서, 경로 파악
	while (cnt != start_point) {
		answer.push_back(route[cnt]);
		cnt = route[cnt];
	}

	cout << answer.size() << "\n";
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}


}


//다익스트라

//단방향 edge였다!!