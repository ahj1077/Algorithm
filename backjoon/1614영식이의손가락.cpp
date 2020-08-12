#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;


int disable;

//짝수면 오른쪽에서 왼쪽세는 방향
//홀수면 왼쪽에서 오른쪽
int cancount;

int finger[6] = { 0,8,6,4,2,8 };
unsigned long long answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> disable;
	cin >> cancount;

	if (cancount == 0) {
		answer = disable - 1;
	}
	else {
		unsigned long long num = disable;
		int sw1 = finger[disable];
		int sw2 = 8 - finger[disable];

		if (disable == 1 || disable == 5) {
			num += ((long long)sw1 * cancount);
			num--;
		}
		else {
			num += ((long long)sw2 * (cancount / 2));
			num += ((long long)sw1 * (cancount - cancount / 2));
			num--;
		}

		answer = num;
	
	}


	cout << answer << "\n";
	
	
	return 0;
}