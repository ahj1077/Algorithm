#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, m, answer = 987654321;
int sr, sc;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
char map[50][50];
bool visit[128][50][50];

class node {
public:
	int r;
	int c;
	int d;
	int keybit;
	node(int rr, int cc, int dd, int kb) : r(rr), c(cc), d(dd), keybit(kb) {}
};

void bfs() {
	queue<node> q;
	visit[0][sr][sc] = true;
	q.push(node(sr, sc, 0, 0));
	bool ok = false;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		int keybit = q.front().keybit;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtr = r + dirr[i];
			int nxtc = c + dirc[i];

			if (nxtr < 0 || nxtr >= n || nxtc < 0 || nxtc >= m) continue;
			
			if (map[nxtr][nxtc] != '#') {
				if (map[nxtr][nxtc] >= 'a' && map[nxtr][nxtc] <= 'f') {
					if (!visit[keybit][nxtr][nxtc]) {
						visit[keybit][nxtr][nxtc] = true;
						int shift_val = (map[nxtr][nxtc] - 'a');
						int getkeybit = keybit | (1 << shift_val);
						q.push(node(nxtr, nxtc, d + 1, getkeybit));
					}
				}
				else if (map[nxtr][nxtc] >='A' && map[nxtr][nxtc] <= 'F'){
					if (keybit & (1 << (map[nxtr][nxtc] - 'A'))) {
						if (!visit[keybit][nxtr][nxtc]) {
							visit[keybit][nxtr][nxtc] = true;
							q.push(node(nxtr, nxtc, d + 1, keybit));
						}
					}
				}
				else if(map[nxtr][nxtc] == '.' || map[nxtr][nxtc] == '0'){
					if (!visit[keybit][nxtr][nxtc]) {
						visit[keybit][nxtr][nxtc] = true;
						q.push(node(nxtr, nxtc, d + 1, keybit));
					}
				}
				else if(map[nxtr][nxtc] == '1'){
					answer = min(answer, d + 1);
					ok = true;
					break;
				}
			}
		}
		if (ok) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sr = i;
				sc = j;
			}
		}
	}

	bfs();
	if (answer == 987654321) answer = -1;
	cout << answer << "\n";
	return 0;
}