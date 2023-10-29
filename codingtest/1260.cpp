#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visit;
queue<int> BFS_Queue;

void DFS(int x) {
	//x 방문
	visit[x] = true;
	cout << x << " ";

	//갈 수 있는 곳 방문
	for (int i = 0; i < static_cast<int>( adj_list[x].size() ); i++) {
		if (!visit[adj_list[x][i]]) DFS(adj_list[x][i]);
	}
}

void BFS( int x ) {
	//x부터 시작이므로 큐에 넣음
	BFS_Queue.push(x);
	visit[x] = true;

	while (!BFS_Queue.empty()) {
		//x방문
		auto a = BFS_Queue.front();
		BFS_Queue.pop();
		cout << a << " ";

		//갈 수 있는 곳을 queue에 넣기
		for (int i = 0; i < static_cast<int>( adj_list[a].size() ); i++) {
			if (!visit[adj_list[a][i]]) { BFS_Queue.push(adj_list[a][i]); visit[adj_list[a][i]] = true; }
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	//visit 초기화
	for (int i = 0; i <= N; i++) {
		visit.push_back(false);
	}

	//adj_list 초기화
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		adj_list.push_back(tmp);
	}

	//adj_list 채우기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	//정점 번호가 작은 것 부터 -> 정렬
	for (int i = 0; i <=N ; i++) {
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	DFS(V);

	cout << "\n";

	//BFS
	//visit 초기화
	for (int i = 0; i <= N; i++) {
		visit[i] = false;
	}

	BFS(V);
}

//DFS