#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, answer;
int map[20][20];

void search(int sr,int sc,int d1,int d2) {
	bool d[101];
	for (int i = 0; i < 101; i++)
		d[i] = false;
	int cnt = 0;

	for (int i = 0; i < d2; i++) {
		if (d[map[sr + i][sc + i]]) {
			return;
		}
		else {
			d[map[sr + i][sc + i]] = true;
			cnt++;
		}
	}

	for (int i = 0; i < d1; i++) {
		if (d[map[sr + d2 + i][sc + d2 - i]]) {
			return;
		}
		else {
			d[map[sr + d2 + i][sc + d2 - i]] = true;
			cnt++;
		}
	}

	for (int i = 0; i < d2; i++) {
		if (d[map[sr + d1+d2 - i][sc -d1+d2-i]] == true) {
			return;
		}
		else {
			d[map[sr + d1+d2-i][sc -d1+d2-i]] = true;
			cnt++;
		}
	}
	for (int i = 0; i < d1; i++) {
		if (d[map[sr + d1 - i][sc - d1 + i]] == true) {
			return;
		}
		else {
			d[map[sr + d1 - i][sc - d1 + i]] = true;
			cnt++;
		}
	}
	answer = max(answer, cnt);
}

void start(int sr, int sc) {
	for (int d1 = 1; sc - d1 >= 0; d1++){
		for (int d2 = 1; sr + d1 + d2 < n && sc + d2 < n; d2++) {
			search(sr,sc,d1,d2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n;
		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j=0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				start(i, j);
			}
		}
		if (answer == 0) answer = -1;
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}