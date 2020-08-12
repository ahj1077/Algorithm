#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;
int R, C;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };

char map[20][20];
bool chk[26];
int answer = 0;

void dfs(int r, int c, int d) {
	
	bool ok = false;

	for (int i = 0; i < 4; i++) {
		int nxtr = r + dirr[i];
		int nxtc = c + dirc[i];

		if (nxtr >= 0 && nxtr < R && nxtc >= 0 && nxtc < C) {
			if (!chk[map[nxtr][nxtc] - 'A']) {
				ok = true;

				chk[map[nxtr][nxtc] - 'A'] = true;
				dfs(nxtr, nxtc, d + 1);
				chk[map[nxtr][nxtc] - 'A'] = false;
			}
		}
	}

	if (!ok) 
		answer = max(answer, d);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}

	chk[map[0][0] - 'A'] = true;
	dfs(0,0,1);
	cout << answer << "\n";
	return 0;
}