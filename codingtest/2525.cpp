#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, m;
	cin >> h >> m;

	int time;
	cin >> time;

	int time_h, time_m;

	time_h = time / 60;
	time_m = time % 60;

	h += time_h;
	m += time_m;

	if (m > 59) {
		m %= 60;
		h++;
	}

	if (h > 23) {
		h %= 24;
	}

	cout << h << " " << m;

	


}
