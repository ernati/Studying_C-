#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>

using namespace std;

struct pair3 {
	int red;
	int green;
	int blue;
	pair3(int, int, int);
};

pair3::pair3(int a, int b, int c) {
	red = a;
	green = b;
	blue = c;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair3> price;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		price.push_back( pair3(a, b, c ) );
	}

	vector<vector<int>> memo;  //각 선택별로 그 시점까지의 최솟값을 담는 메모

	//memo 초기화
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int i = 0; i < 3; i++) {
			tmp.push_back(0);
		}
		memo.push_back(tmp);
	}

	//초기값
	memo[0][0] = price[0].red;
	memo[0][1] = price[0].green;
	memo[0][2] = price[0].blue;

	for (int i = 1; i < N; i++) {
		//한 시점의 값은 전 시점에서의 경우의 최솟값이다.
		memo[i][0] = price[i].red + min(memo[i - 1][1], memo[i - 1][2]);
		memo[i][1] = price[i].green + min(memo[i - 1][0], memo[i - 1][2]);
		memo[i][2] = price[i].blue + min(memo[i - 1][0], memo[i - 1][1]);
	}

	cout << min({ memo[N - 1][0], memo[N - 1][1], memo[N - 1][2] });
}

//1번 집은 2번집과 같이 않아야 함.
//N번 집은 N-1번 집과 같지 않아야함.
//i번 집의 색은 i-1, i+1번 집의 색과 같지 않아야함.

//즉, 모든집이 이웃하지 않아야함.
//모든 집에서 최소값을 칠하면 좋겠지만...
//브루트포스는 3 * 2 * 2 * 2.... 이 경우를 모두 세면 된다
//집마다 고유의 가격 3개가 있는거잖아...?
//항상 최소의 가격만 고른다고 생각하면 어때? - 그리디 알고리즘
//역시 완벽하진 않아... 
//그러면 어떻게 해야할까?

//점화식이라면...?
//어떤 시점에 하나를 선택할 때, 이전 것과 지금거의 합을 생각해보는건 어떨까?
// 맨 처음이 아닌 이상, 선택을 할 때, 두 가지 경우가 넘어와. 그 때, 두 가지 경우에 대해서, 가능한 경우는 총 4가지야.
//거기서 최솟값을 고르자는 거지.

//예제 
//처음에 39, 44를 넘겨
//두번째는 39 -> 32, 55 // 44 -> 32, 83 인거지
//그러면 39+32 // 44 + 32 
// 경우가 2개가 다시 넘어가면, 또 최솟값인 인덱스를 또 넘겨주는 거지.
//근데 위 경우에서, 두 경우가 똑같이 하나의 경우를 골랐어. 둘다 32를 골랐지.
//그러면? -> 다시 처음처럼 2개를 넘기면 되는거야.

//다음 시점으로 넘긴다가 아니고
//이 시점에서 빨간색을 칠했을 때의 최소 가격은, 전 시점에서 초록색이나, 파란색을 칠했을 때의 최소가격 중 최소값에다가 빨간색을 칠하는 거지.

//생각해보니, 아이디어를 생각하긴 했어. 근데 구현을 개떡같이 할 생각을 햇어.
//저 값들을 넘겨준다를 변수로 넘겨주는게 아니고, 써놓으면 되지, 메모이제이션!



 
