#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string T;

	cin >> N;
	cin >> T;

	stack<char> stk;
	int finish_cursor = T.length() - 1;
	string answer;
	int cursor = 0;

	while ( cursor < finish_cursor ) {
		//방문
		char current = T[cursor];
		if (current == 'S') {
			answer += "S";

			if (T[cursor + 1] == 'U') {
				cursor += 2;
				continue;
			}
			else { //T[cursor+1] == 'S'
				answer += "N";
				stk.push('U'); 
				cursor++;
				finish_cursor--;
			}

		}
		else { //current - 'U'
			answer += "U";

			if (T[cursor + 1] == 'S') {
				cursor += 2;
				continue;
			}
			else { //T[cursor+1] == 'U'
				answer += "N";
				stk.push('S');
				cursor++;
				finish_cursor--;
			}
			
		}

	}

	cout << answer.length() << "\n" << answer;
}

//학생 수 N은 항상 짝수, 절반은 s , 절반은 u를 받는다.
// 성적이 길이 N인 문자열 T로 주어진다 -> 예시 : SUUUSUSSSUSUUU...
// 내가 할 수 있는 일은 3가지
// 1. 현재 커서의 위치에 SU를 추가
// 2. 커서가 맨 왼쪽에 있지 않은 경우, 커서를 왼쪽으로 한 글자 움직인다
// 3. 현재 커서의 위치에 US를 추가한다.
//1번과 3번을 수행하면 커서는 "추가한 문자열"의 바로 뒤로 이동한다.
//시행을 "최소한으로 사용"하여 학생들이 성적을 모두 입력하는 방법을 하나 찾자.


//string과 cursor를 따로 구현해서 움직이는건 어떨까
//SU
//가능한 경우는 SUSU SUUS SSUU
//입력으로 SUSUSU USUSUS 이런것만 받는다면 답은 간단하다.
//또한, 커서를 연속 2번 옮기는 것은 의미가 없다. 즉 중간에 한번씩만 들어가게 된다
// SU 에서 커서를 한번쓰면, SSUU 혹은 SUSU인데, SUSU는 커서가 필요 없다. 즉 SSUU만 유효하다.
// 그러므로, SU가 나온후 커서가 나온다는 것은 무조건 SU가 다시 등장한다.
//US -> UUSS
// SUSUUS -> SU 발견 -> SUUS -> SU발견 -> US -> US 발견 -> empty string -> 답은 SSU
//SNSNSSUUNU -> SSSUSUUSUUSSUU -> SNSNSSUUNU
// UUS

//stack 하나 준비 , finish cursor는 초기값은 문자열 길이 - 1 , 출력 문자열은 emptystring, cursor의 초기값은 0 이다.
//받은 문자열을 처음부터 조사한다.
//S를 만난다 -> 출력 문자열에 S를 추가
//현재 위치 다음 위치를 봤는데 U다 -> 다음을 건너뛰고 현재 + 2 로 커서를 옮긴다.
//다음 위치가 같은 S다 -> 출력 문자열에 N을 추가하고 stack에 U를 넣는다. -> 커서를 +1 한다. -> fisnish cursor를 -1 한다.

//U는 반대로 하면 된다.

//이때 cursor가 finish cursor와 같아지면 종료하고 출력 문자열을 출력한다.