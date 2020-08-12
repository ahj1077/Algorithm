#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
long long total = 1;
long long garo[200002];
long long sero[200002];
int group[200002];

void addnum(int r,int c) {
	int grp = r + c - 1;
	
	if (grp % 2 == 0) {
		//짝수므로 오른쪽 위로
		int gap = min(r - 1, n - c);
		cout << garo[grp] + gap << " ";
		total += (garo[grp] + gap);
	}
	else {
		//홀수므로 왼쪽 아래로
		int gap = min(n - r, c - 1);
		cout << sero[grp] + gap << " ";
		total += (sero[grp] + gap);
	}
}

void make() {
	for (int i = 1; i <= n; i++) {
		group[i] = i;
	}

	int cnt = 1;
	for (int i = n + 1; i <= 2 * n - 1; i++) {
		group[i] = n - cnt;
		cnt++;
	}

	sero[1] = 1;
	garo[2] = 2;

	for (int i = 4; i < 2 * n; i+=2) {
		garo[i] = garo[i - 2] + group[i - 1] + group[i - 2];
	}

	for (int i = 3; i < 2 * n; i+=2) {
		sero[i] = sero[i - 2] + group[i - 1] + group[i - 2];
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;

	cin >> n >> k;

	string s;
	cin >> s;

	make();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			addnum(i, j);
		}
		cout << "\n";
	}

	int r = 1, c = 1;

	/*for (int i = 0; i < k; i++) {
		char dir = s[i];
		if (dir == 'U') {
			r--;
			addnum(r, c);
		}
		else if (dir == 'D') {
			r++;
			addnum(r, c);
		}
		else if (dir == 'L') {
			c--;
			addnum(r, c);
		}
		else if (dir == 'R') {
			c++;
			addnum(r, c);
		}
	}*/
	cout << total << "\n";

	return 0;
}