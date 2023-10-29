#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max_size = 0;

	vector<string> strings;
	for (int i = 0; i < 5; i++) {
		string tmp;
		cin >> tmp;
		if (tmp.length() > max_size) { max_size = tmp.length(); }
		strings.push_back(tmp);
	}

	string answer;

	//문자열 추출
	for (int i = 0; i < max_size; i++) {
		for (int j = 0; j < 5; j++) {
			// i가 string[j]의 length보다 작을 경우 -> string[j]에 i idx가 존재할 경우
			if (i < strings[j].length()) { answer += strings[j][i]; } //answer에 추가
		}
	}

	cout << answer;
}

//받은 문자열 집합들을 세로로 읽어서 하나로 합치면 된다.
//총 5줄의 입력

//수 : 0 ( 아스키 48 ) ~ 9 (아스키 57)
//영어 : a ( 97 ) ~ z(  122)
//A(65) ~ Z(90)