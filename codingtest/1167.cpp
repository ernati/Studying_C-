#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> visit;
queue<int> BFS_Queue;
vector<int> dist;

void BFS(int x) {
	//x방문
	visit[x] = true;
	BFS_Queue.push(x);

	while (!BFS_Queue.empty()) {
		auto tmp = BFS_Queue.front();
		BFS_Queue.pop();

		for (int i = 0; i < adj_list[tmp].size(); i++) {
			if (!visit[adj_list[tmp][i].first]) {
				visit[adj_list[tmp][i].first] = true;
				dist[adj_list[tmp][i].first] = dist[tmp] + adj_list[tmp][i].second;
				BFS_Queue.push(adj_list[tmp][i].first);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V; cin >> V;

	//adj_list 초기화
	for (int i = 0; i <= V; i++) {
		vector<pair<int,int>> tmp;
		adj_list.push_back(tmp);
	}

	//visit 초기화
	for (int i = 0; i <= V; i++) {
		visit.push_back(false);
	}

	//adj_list 받기
	for (int i = 0; i < V; i++) {
		vector<int> tmp2;
		while (true) {
			int a;
			cin >> a;
			if (a == -1) break;
			else tmp2.push_back(a);
		}

		int start = tmp2[0];
		//2개씩 뽑아서, adj_list에 넣는다.
		for (int i = 1; i < tmp2.size() - 1; i += 2) {
			adj_list[start].push_back(make_pair(tmp2[i], tmp2[i + 1]));
			/*adj_list[tmp2[i]].push_back(make_pair(start, tmp2[i + 1]));*/
		}
	}

	////adj_list print
	//for (int i = 1; i <= V; i++) {
	//	cout << i <<" -> ";
	//	for (int j = 0; j < adj_list[i].size(); j++) {
	//		cout << " ( " << adj_list[i][j].first << ", " << adj_list[i][j].second << " ) ";
	//	}
	//	cout << "\n";
	//}

	//dist 초기화
	for (int i = 0; i <= V; i++) {
		dist.push_back(0);
	}

	BFS(1);

	int max_V = 1;

	//cout << "dist is " << dist[1] << " ";

	//가장 먼 V찾기
	for (int i = 2; i <= V; i++) {
		//cout << dist[i] << " ";
		if (dist[max_V] < dist[i]) {
			max_V = i;
		}
	}

	//cout << "\n===============================\n";

	//visit 초기화, dist 초기화
	for (int i = 1; i <= V; i++) {
		visit[i] = false;
		dist[i] = 0;
	}

	BFS(max_V);

	int answer = dist[1];

	//cout << "dist is " << dist[1] << " ";

	//가장 먼 거리 찾기
	for (int i = 2; i <= V; i++) {
		//cout << dist[i] << " ";
		answer = max(answer, dist[i]);
	}

	//cout << "\n===============================\n";

	cout << answer;

}

//정점이 V개
//간선은 V-1개
//입력은 정점 도착점 거리

//가장 단순한 풀이는, 하나하나 출발해서 길이를 잰다.
//가장 큰 길이를 반환한다.

//혹시... 하나에서 가장 먼 곳을 찾은후에, 거기서 제일 먼곳을 보면 그게 지름인가?