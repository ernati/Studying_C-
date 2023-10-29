#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int B;

	cin >> N;
	cin >> B;

	long answer = 0;

	for (int i = N.length()-1; i>=0; i--) {
		int tmp = static_cast<int>(N[i]); //아스키코드로 변환
		int i_tmp = N.length() - 1 - i; //i는 맨 마지막부터 훑지만, 더할 때는 0제곱부터 더해야한다.
		if (48 <= tmp && tmp <= 57) { // N[i]가 0~9
			tmp -= 48;
			answer += pow(B, i_tmp) * tmp;
		}
		else { //N[i]가 10~35
			tmp -= 55; 
			answer += pow(B, i_tmp) * tmp;
		}
	}

	cout << answer;


}

//'0' : 48 ~ '9' : 57
//'A' : 65 ~ 'Z' : 90
