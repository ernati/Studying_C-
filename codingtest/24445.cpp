#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

vector< vector<int> > adj_list; // 0~N개의 벡터
vector<bool> visit; // 0 ~ N까지
queue<int> BFS_Queue;
vector<int> visit_order;
vector<int> answer;

void BFS(int x)
{
	// 1. x 방문
	visit[x] = true;
	//q에 넣기
	BFS_Queue.push(x);

	//queue가 빌때가지 시행
	while (!BFS_Queue.empty()) {
		//queue의 front 정점을 방문
		int tmp = BFS_Queue.front();
		//pop
		BFS_Queue.pop();

		//방문 표시
		visit[tmp] = true;
		visit_order.push_back(tmp);

		//x에서 방문할 수 있는 곳들을 방문
		for (int i = 0; i < adj_list[tmp].size(); i++) {
			if (!visit[adj_list[tmp][i]]) {
				//방문 - queue에 정점 집어넣기
				visit[adj_list[tmp][i]] = true; // 이떄 방문표시를 해놔야 queue에 반복해서 들어가지 않는다.
				BFS_Queue.push(adj_list[tmp][i]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	//visit 초기화
	for (int i = 0; i <= N; i++) {
		visit.push_back(false);
	}

	//adj_list 초기화
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		adj_list.push_back(tmp);
	}

	//adj_list 받아오기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	//오름차순 방문이므로 sort
	for (int i = 1; i < adj_list.size(); i++) {
		sort(adj_list[i].begin(), adj_list[i].end(), greater<>());
	}

	BFS(R);

	//answer 초기화
	for (int i = 0; i <= N; i++) {
		answer.push_back(0);
	}
	
	//cout << "=============================\n";
	for (int i = 0; i < visit_order.size(); i++) {
		//cout << visit_order[i] << "\n";
		answer[ visit_order[i] ] = i + 1;
	}
	//cout << "=============================\n";
	for (int i = 1; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}

//N , M , R

