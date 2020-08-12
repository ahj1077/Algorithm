#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int n, m, a, b, k;
int sr, sc, er, ec;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
bool map[500][500];
bool visit[500][500];
int answer = 0;
bool can = false;

class node {
public:
	int r;
	int c;
	int d;

	node(int rr, int cc, int dd) : r(rr), c(cc), d(dd) {}
};

void bfs() {
	queue<node> q;
	q.push(node(sr, sc, 0));
	visit[sr][sc] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		if (r == er && c == ec) {
			answer = d;
			can = true;
			break;
		}
		for (int i = 0; i < 4; i++) {

			bool ok = true;
			for (int j = 0; j < a && ok; j++) {
				for (int k = 0; k < b && ok; k++) {
					int nxtr = r + j + dirr[i];
					int nxtc = c + k + dirc[i];
					
					if (j == 0 && k == 0) {
						if (nxtr < 0 || nxtr >= n || nxtc < 0 || nxtc >= m || !map[nxtr][nxtc] || visit[nxtr][nxtc]) {
							ok = false;
						}
					}
					else {
						if (nxtr < 0 || nxtr >= n || nxtc < 0 || nxtc >= m || !map[nxtr][nxtc]) {
							ok = false;
						}
					}
				}
			}
			if (ok) {
				visit[r + dirr[i]][c + dirc[i]] = true;
				q.push(node(r + dirr[i], c + dirc[i], d + 1));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
			map[i][j] = true;
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = false;
	}
	cin >> sr >> sc;
	cin >> er >> ec;
	sr--, sc--, er--, ec--;


	bfs();
	
	if (can)
		cout << answer << "\n";
	else
		cout << -1 << "\n";
	return 0;
}