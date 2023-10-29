#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visit;
vector<int> visit_order;
vector<int> answer;

void DFS(int x)
{
	//1. x 방문 처리
	visit[x] = true;
	visit_order.push_back(x);

	//2. 갈 수 있는 곳들을 갈 수 있는지 확인하고, 재귀로 실행
	for (int i = 0; i < adj_list[x].size(); i++)
	{
		//2-1. 방문할수 있는지 확인
		if (!visit[adj_list[x][i]]) {
			DFS(adj_list[x][i]);
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

	//방문초기화
	for (int i = 0; i <= N; i++)
	{
		visit.push_back(false);
	}

	//adj_list 초기화
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		adj_list.push_back(tmp);
	}

	//간선 정보 u,v
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//양방향 이므로 둘다
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	////adj_list print
	//for (int i = 1; i < adj_list.size(); i++) {
	//	for (int j = 0; j < adj_list[i].size(); j++) {
	//		cout << adj_list[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	
	//오름차순 방문이므로, adj_list를 sort
	for (int i = 1; i <= N; i++) {
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	DFS(R);

	//visit order엔 방문한 순서대로 정점들이 들어있음.
	//answer초기화
	for (int i = 0; i <= N; i++) {
		answer.push_back(0);
	}

	//visit order를 훑어서, answer의 "정점번호"번째 요소의 값을, vector index로 하면된다.
	for (int i = 0; i < visit_order.size(); i++) {
		answer[visit_order[i]] = i+1;
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << "\n";
	}
	
}

//N , M , R

//예시
// 1,2,3,4,5,6
// 1-3, 1-4
//2-3 2-4 2-5
//3-6
//4-6
//5-6

//   1 - 3
//   |   |
//   4 - 2 - 5  //입체도형으로 2 위에 6이 있고, 3,4,5,와 연결되어있다.
// 
// 
// 6번 시작 예상 방문 순서 :  6 - 3 - 1 - 4 - 2 -5
//예상 답 : 3 5 2 4 6 1