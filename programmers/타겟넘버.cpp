#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

bool isprime[10000000];
string s;
int ans = 0;
void chk(string number) {
	int prime = 0;
	int cnt = 1;
	for (int i = 0; i < number.size(); i++) {
		prime += ((number[number.size() - i - 1] - '0') * cnt);
		cnt *= 10;
	}

	if (isprime[prime]) {
		ans++;
	}
}
void dfs(int getsu, string number, bool *_ok) {
	if (getsu == number.size()) {
		chk(number);
		return;
	}

	bool ok[8];
	for (int i = 0; i < 8; i++)
		ok[i] = _ok[i];

	for (int i = 0; i < s.size(); i++) {
		if (!ok[i]) {
			ok[i] = true;
			number.push_back(s[i]);
			dfs(getsu, number, ok);
			number.pop_back();
			ok[i] = false;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	s = numbers;

	for (int i = 1; i < 10000000; i++) 
		isprime[i] = true;
	isprime[1] = false;
	for (int i = 2; i < 5000000; i++) {
		if (isprime[i] == true) {
			for (int cnt = 2; i * cnt < 10000000; cnt++) {
				isprime[cnt*i] = false;
			}
		}
	}

	bool ok[8];
	for (int i = 0; i < 8; i++)
		ok[i] = false;

	for (int getsu = 1; getsu <= numbers.size(); getsu++) {
		dfs(getsu,"", ok);
	}
	
	answer = ans;
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "011";
	solution(s);

	return 0;
}