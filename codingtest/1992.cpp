#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;


//리턴 0 : 0으로 채우져있음
//리턴 1 : 1로 채워져있음
//리턴 2 : 한문자로 채워져있지 않음.
int check(vector<vector<int>>& movie, int start_x, int start_y, int n) {
	int num;
	//0이나 1로만 되어있는지 확인
	for (int i = start_x; i < start_x + n; i++) {
		for (int j = start_y; j < start_y + n; j++) {
			if (i == start_x && j == start_y) { num = movie[i][j]; }
			else {
				if (num != movie[i][j]) { return 2; }  
			}
		}
	}

	if (num == 1) { return 1; }
	else {
		return 0;
	}
}

void check_movie(vector<vector<int>>& movie, int start_x, int start_y, int n) {

	//1. 한 문자로 채워져있는지 확인
	int check_num = check(movie, start_x, start_y, n);

	//2. 만약 0이나 1로 문자로 채워져있음 -> 출력 후 종료
	if (check_num != 2) { cout << check_num; return; }
	else {
		//3. 안채워져있음 -> 4분할 재귀
		cout << "(";
		int num = n / 2;
		check_movie(movie, start_x, start_y, num );
		check_movie(movie, start_x, start_y+num, num);
		check_movie(movie, start_x+num, start_y, num);
		check_movie(movie, start_x + num, start_y + num, num);
		cout << ")";

		return;
	}

}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	vector<vector<int>> movie;

	//movie 초기화
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		string a;
		cin >> a; //11110000
		for (int j = 0; j < N; j++) {
			char b = a[j]; // '1'
			int c = static_cast<int>(b - '0');
			tmp.push_back(c);
		}
		movie.push_back(tmp);
	}

	check_movie(movie, 0, 0, N);


}

//재귀 + 출력