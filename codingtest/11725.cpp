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

vector<int> my_parent_node;

void BFS(int x) {

	//1. x 방문
	visit[x] = true;
	BFS_Queue.push(x);

	while (!BFS_Queue.empty()) {
		int a = BFS_Queue.front();
		BFS_Queue.pop();

		for (int i = 0; i < adj_list[a].size(); i++) {
			if (!visit[adj_list[a][i]]) {
				BFS_Queue.push(adj_list[a][i]);
				visit[adj_list[a][i]] = true;
				my_parent_node[adj_list[a][i]] = a;
			}
		}
	}

}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	//adj_list 초기화
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		adj_list.push_back(tmp);
	}

	//visit, my_parent 초기화
	for (int i = 0; i <= N; i++) {
		visit.push_back(false);
		my_parent_node.push_back(0);
	}

	//adj_list update
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	BFS(1);
	
	//출력
	for (int i = 2; i <= N; i++) {
		cout << my_parent_node[i] << "\n";
	}

}

//노드 수 N
// 트리 상에서 연결된 두 정점 - 양방향
// 트리 : 위계 -> BFS
// 시작 노드를 1로 하고, BFS로 방문.
// 어떤 노드에 방문했을 때, 자기의 전 노드를 기록하면 될듯.
//