#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

pair<int,int> simulatneous(int a, int b, int c, int d, int e, int f) {
	for (int x = -999; x < 1000; x++) {
		for (int y = -999; y < 1000; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				return { x,y };
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	
	auto answer = simulatneous(a, b, c, d, e, f);
	cout << answer.first << " " << answer.second;
}

// ax + by = c
// dx + ey = f
// 해는 무조건 존재한다
// ax + by = c --> 해가 존재할테니 둘다 0인 경우는 없으니
// a가 0 -> y값
// b가 0 -> x값
// 그렇지 않다면? ->  

