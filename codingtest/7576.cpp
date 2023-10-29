#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> box;
vector<vector<bool>> visit;
queue<pair<int, int>> BFS_Queue;
vector<pair<int, int>> dxdy;

vector<vector<int>> days;


void BFS( )
{

	//queue가 비어있지 않으므로 바로 시작
	while (!BFS_Queue.empty())
	{
		//1. 방문
		auto a = BFS_Queue.front();
		BFS_Queue.pop();

		//방문 표시
		visit[a.first][a.second] = true;
		box[a.first][a.second] = 1;

		//cout << "queue.front is  : " << a.first << " " << a.second << "\n";

		//방문할 수 있는 곳 ㄱㄱ
		for (int i = 0; i < 4; i++) {
			//방문 좌표 생성
			int x, y;
			x = a.first + dxdy[i].first;
			y = a.second + dxdy[i].second;

			//cout << "x, y is : " << x << " " << y << "\n";

			//방문 좌표 방문여부
			if (x >= 0 && x < visit.size() && y >= 0 && y < visit[0].size() && 
				box[x][y] == 0 && !visit[x][y]) {
				BFS_Queue.push(make_pair(x, y));
				visit[x][y] = true;
				box[x][y] = 1;
				days[x][y] = days[a.first][a.second]+1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int tmp;

	//dxdy 초기화
	dxdy.push_back(make_pair(-1, 0)); // 왼쪽
	dxdy.push_back(make_pair(1, 0)); //오른쪽
	dxdy.push_back(make_pair(0, 1)); //위쪽
	dxdy.push_back(make_pair(0, -1)); //아래쪽



	//box 초기화
	for (int i = 0; i < M; i++) {
		vector<int> tmptmp;
		box.push_back(tmptmp);

		//visit도 초기화
		vector<bool> tmptmptmp;
		visit.push_back(tmptmptmp);

		//days 초기화
		vector<int> tmptmp2;
		days.push_back(tmptmp2);
	}

	

	//box에 토마토 넣기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			box[i].push_back(tmp);

			//visit 초기화
			visit[i].push_back(false);

			//BFS_Queue에 익은 토마토 시작점 넣기
			if (tmp == 1)
			{
				auto a = make_pair(i, j); // int, int 
				BFS_Queue.push(a);

				//days 초기화
				days[i].push_back(1);
			}

			//진행 불가 - days도 -1로
			else if (tmp == -1) {
				//days 초기화
				days[i].push_back(-1);
			}

			else {
				//days 초기화
				days[i].push_back(0);
			}

		}
	}

	//정답1 : 모든 토마토가 익어있는 상태 -> 0을 출력
	//box 확인
	int zero = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 0) { zero++; }
		}
	}

	if (zero == 0) { cout << 0; return 0; }

	BFS();

	//days 확인
	//정답 2 : days에 0이 존재 -> -1 출력
	//정답 3 : days에 0 이 없음 -> 최대값 -1 출력

	int max = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (days[i][j] == 0) { cout << -1; return 0; }
			if (days[i][j] > max) { max = days[i][j]; }
		}
	}

	cout << max - 1; 

	return 0;
	

}

//토마토가 익는다. == 토마토를 시작점으로 BFS를 돌려서 모두 방문한다. ! ㅁㅊ
//격자 BFS - 인접행렬이 필요 없다.
//days : 0인 값이 존재 -> -1을 출력
// 모두 채워짐 -> 최대값 - 1 이 정답
//시작부터 모든 토마토가 익어있는 상태 -> 0