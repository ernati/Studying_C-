#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

vector<pair<int, int>> ladder_list;
vector<pair<int, int>> snake_list;
queue<int> BFS_Queue;
vector<int> dist;

bool isSnake(int x) {
	for (int i = 0; i < snake_list.size(); i++) {
		//x가 뱀칸 중 하나라면
		if (snake_list[i].first == x) { return true; }
	}
	return false;
}

bool isladder(int x) {
	for (int i = 0; i < ladder_list.size(); i++) {
		//x가 사다리칸 중 하나라면
		if (ladder_list[i].first == x) { return true; }
	}
	return false;
}

int findladder(int x) {
	int a;

	for (int i = 0; i < ladder_list.size(); i++) {
		if (ladder_list[i].first == x) { a = ladder_list[i].second; break; }
	}

	return a;
}

void DFS( int x ) {
	////x 방문
	//cout << "visit " << x << "\n";
	//if (x == 100) {
	//	cout << dist[x] << "\n";
	//}

	//사다리칸이면, 바로 사다리로 직행
	if (isladder(x)) {
		int a = findladder(x);
		if (dist[a] == 0) { dist[a] = dist[x]; }
		else {
			dist[a] = min(dist[a], dist[x]);
		}
		DFS( a );
	}

	//6칸 이내에 사다리 칸이 없다면 6칸 전진, 사다리가 있어도 6칸은 전진함. 그 6칸이 
	//1. 사다리칸부터 검사
	for (int i = x + 1; i <= x + 6; i++) {
		if ( i<=100 && isladder(i)) { //i 칸이 사다리
			//거리 update -> 현재 거리보다 최솟값이면 update
			//아직 안 도착해본 곳이라면
			if (dist[i] == 0) { dist[i] = dist[x] + 1; }
			else {
				dist[i] = min(dist[i], dist[x] + 1);
			}
			DFS(i);
		}
	}

	//2. 6칸 후부터 검사, 뱀칸이면 안감, 가장 큰 수의 칸을 전진
	for (int i = x + 6; i >= x+1; i--) {
		if ( i<=100  && !isSnake(i)) //뱀 칸이 아니면
		{
			if (dist[i] == 0) { dist[i] = dist[x] + 1; }
			else {
				dist[i] = min(dist[i], dist[x] + 1);
			}
			DFS(i);
			break; // 가장 많이 전진하기만 하면 되므로.
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		int a, b;
		cin >> a >> b;
		ladder_list.push_back(make_pair(a, b));
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		snake_list.push_back(make_pair(a, b));
	}

	//dist 초기화
	for (int i = 0; i <= 100; i++) {
		dist.push_back(0);
	}

	DFS(1);

	cout << dist[100];
}

//격자 BFS 베이스에, 칸을 넘나드는 무언가가 있는 것.
//한 칸에 방문해서 큐에 갈 수 있는 칸을 넣을 때, 격자 이동 대신, 사다리 or 뱀을 넣으면 된다.
//어... 1부터 가니까, 경우의 수가 너무나도 많다.
//근데 사실, 사다리칸은 필수적으로 방문해야 하는 곳이야.

//예를 들어서
// 12 98
// 6 30 
//그리고, 이동할 때, 주사위는 최대 6칸인데, 만약 6칸 안에 사다리가 없다면, 무조건 6칸을 전진하면 됨.
//사다리가 있더라도, 사다리는 모두 들리고, 6칸도 가면 됨.
//그런데 그 6칸이 뱀칸이면? 5칸 가야지
//그러니까 칸 검사는 큰 순서부터 검사해야됨.