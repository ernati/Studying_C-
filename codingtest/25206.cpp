#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double credit_total { 0.0 }; 
	double amount_of_total{ 0.0 };


	for (int i = 0; i < 20; i++) {
		string a, c;
		double b;

		cin >> a >> b >> c;

		//P 거르기
		if (c == "P") {
		}

		else {


			double point;

			if (c == "A+") {
				point = 4.5;
			}
			else if (c == "A0") {
				point = 4.0;
			}
			else if (c == "B+") {
				point = 3.5;
			}
			else if (c == "B0") {
				point = 3.0;
			}
			else if (c == "C+") {
				point = 2.5;
			}
			else if (c == "C0") {
				point = 2.0;
			}
			else if (c == "D+") {
				point = 1.5;
			}
			else if (c == "D0") {
				point = 1.0;
			}
			else {
				point = 0.0;
			}

			credit_total += b;

			amount_of_total += point * b;

		}

	}
	cout << fixed; //소수점 고정
	cout.precision(5);
	cout << amount_of_total / credit_total;

	

}