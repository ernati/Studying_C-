#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visit;
vector<int> tree;
queue<int> BFS_Queue;

bool check_cycle(int start, int end) {
	bool start_ = true;
	bool end_ = true;

	//tree안에 start와 end가 있는지 확인한다.
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i] == start) { start_ = false; }
		if (tree[i] == end) { end_ = false; }
	}

	//start와 end 둘다 있다면, 둘다 false이므로, 리턴값은 false
	//나머지 경우는 모두 true가 된다.
	return start_ || end_;
}

bool check_tree() {
	//1. 체크용 vector 생성
	vector<int> chk;
	for (int i = 0; i < adj_list.size() - 1; i++) {
		chk.push_back(0); //0~N-1
	}

	//2. 안에 모든 정점들이 있는지 확인
	for (int i = 0; i < tree.size(); i++) {
		//i번째의 원소가 n이다 -> chk[n-1]++
		chk[tree[i] - 1]++;
	}

	//3. 하나라도 0인게 잇으면 false
	for (int i = 0; i < chk.size(); i++) {
		if (chk[i] == 0) { return false; }
	}

	//4. 다 채워져있으면, true
	return true;
}

void BFS() {
	//1을 넣고 시작
	BFS_Queue.push(1);
	tree.push_back(1);

	while (!BFS_Queue.empty()) {
		auto current = BFS_Queue.front();
		BFS_Queue.pop();
		visit[current] = true;

		for (int i = 0; i < adj_list[current].size(); i++) {
			int tmp = adj_list[current][i];

			if (!visit[tmp]) {
				if (check_cycle(current, tmp)) {
					visit[tmp] = true;
					BFS_Queue.push(tmp);
					tree.push_back(tmp);
				}
			}
		}
	}

}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M; cin >> N >> M;
		//visit 초기화
		for (int i = 0; i <= N; i++) {
			visit.push_back(false);
		}

		//adj_list 초기화
		for (int i = 0; i <= N; i++) {
			vector<int> tmp;
			adj_list.push_back(tmp);
		}

		//adj_list 입력
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}

		/*BFS();*/

		cout << N - 1 << "\n";
	}
}


//T : 테스트 케이스
//N : 정점 수
//M : 엣지 수 - 양방향


//모든 엣지들을 최소 힙에 넣고 시작한다. ( 가중치가 존재할 경우 )
//엣지들을 꺼낸다.
//트리 배열에 엣지를 넣기전에, 이 엣지가 cycle을 발생시키는 지 확인한다.
//그렇지 않다면, 넣는다.

//12345678 9
//9가 한가운데 있고, 1~8이 9에 하나씩 연결되어있는 그래프라고 하자.

