#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visit;
vector<int> thenumberofnode;

void DFS(int current, int parent) {
	//current방문
	visit[current] = true;

	//자식들 방문
	for (int i = 0; i < adj_list[current].size(); i++) {
		int tmp = adj_list[current][i];
		if (!visit[tmp]) {
			DFS(tmp, current);
		}
	}

	//부모 노드가 있다면, 값을 더해준다.
	if (parent != -1) { thenumberofnode[parent] += thenumberofnode[current]; }
}




int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q; 
	cin >> N >> R >> Q;

	//adj_list 초기화
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		adj_list.push_back(tmp);
	}

	//adj_list 받기
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	//visit 초기화
	for (int i = 0; i <= N; i++) {
		visit.push_back(false);
	}

	//서브트릐 노드 수 
	for (int i = 0; i <= N; i++) {
		thenumberofnode.push_back(1);
	}

	DFS(R, -1);

	for (int i = 0; i < Q; i++) {
		int u;
		cin >> u;
		cout << thenumberofnode[u] << "\n";
	}
}

// N : 정점의 수, R : 루트의 번호, Q : query의 수
//그 밑으로 N-1만큼의 엣지 정보
//그 다음 Q줄에 걸쳐서 U가 하나씩 주어진다.

//그래프를 만들고 -> 그러면 트리가 됨.
//그 후, Q를 해결하려면 

//R을 기준으로 트리를 생성
// -> BFS를 돌리면서, 


