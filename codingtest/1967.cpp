#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

vector<bool> visit;
vector< vector<pair<int, int> > > adj_list_weight; //adj_list_weight[i][j] -> (a,b) ==> i에서 접근 할 수 있는 j번째 노드는 a이고, weight는 b

int max_value;
int max_idx;

void DFS(int x, int dist)
{
	//1. 방문
	visit[x] = true;

	//2. x에서 방문 가능한 노드들 방문
	for (int i = 0; i < adj_list_weight[x].size(); i++) {
		int son = adj_list_weight[x][i].first;
		if (!visit[son]) {
			//방문 전, max값 update
			if (max_value < dist + adj_list_weight[x][i].second) {
				max_value = dist + adj_list_weight[x][i].second;
				max_idx = son;
			}

			//방문
			DFS(son, dist + adj_list_weight[x][i].second );
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	//visit 초기화
	for (int i = 0; i <= n; i++) {
		visit.push_back(false);
	}

	//adj_list_weight 초기화
	for (int i = 0; i <= n; i++) {
		vector<pair<int, int>> tmp;
		adj_list_weight.push_back(tmp);
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b, c ;
		cin >> a >> b >> c;

		adj_list_weight[a].push_back(make_pair(b, c));
		adj_list_weight[b].push_back(make_pair(a, c));
	}

	max_value = 0;
	max_idx = 1;
	DFS(max_idx, 0);

	////vertex 1로부터 가장 먼 노드 : max_idx
	//cout << "가장 먼 노드 : " << max_idx << "\n";
	//cout << "거리 : " << max_value << "\n";

	int answer_vertex_1 = max_idx;

	//visit 초기화
	for (int i = 1; i <= n; i++) {
		visit[i] = false;
	}

	//값들 재 초기화
	max_value = 0;
	DFS(max_idx, 0);

	/*cout << "가장 먼 노드 : " << max_idx << "\n";
	cout << "거리 : " << max_value;*/

	cout << max_value;
}

//가중치 그래프
//그리디 알고리즘으로 하지 않았나?
//음 브루트포스라면
//각 노드별로, 모든 노드까지의 거리를 구해. 그 거리중에 최대값을 골라
//각 노드별로 가질 수 있는 최대값 중 가장 큰 값이 정답이야.
//음 결국, 리프노드끼리의 연결 경우의 수 중에서 최대값을 구하면 돼.
//아 그러면, 루트노드를 기준으로 왼쪽 서브트리와 오른쪽 서브트리의 리프노드들이 있잖아.
//왼쪽 서브트리의 리프에서 루트까지의 가중치 최대 + 오른쪽 서브트리의 리프에서 루트까지의 가중치 최대 = 최대 지름
//
// 
//루트 : 1
//그렇다면 이제 남은건 리프노드 찾기
//1의 자식 노드들을 queue에 채우고, BFS 출발
//BFS의 종료 시점의 노드들 -> 리프 노드들
//지나온 에지의 가중치 값들의 합 + 출발한 자식노드와 루트 사이의 가중치의 합
// 중 최대값인 2개의 합이 지름이다.


//해답
//어떠한 정점에서 가장 먼 정점은, 무조건, 지름의 한 정점 중 하나가 된다,
//그리고 지름의 한 정점에서 가장 먼 정점은, 지름의 다른 한 정점이 된다.
//와 개소름...
