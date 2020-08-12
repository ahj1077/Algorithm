#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, sr, sc, time, answer;
int map[50][50];
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
vector<int> pipe[8];

class node{
public:
	int r;
	int c;
	int d;
	node(int rr, int cc, int dd) : r(rr), c(cc), d(dd) {}
};
int bfs() {
	bool visit[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
	int cnt = 1;

	queue<node> q;
	q.push(node(sr,sc,1));
	visit[sr][sc] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		for (int i = 0; i < pipe[map[r][c]].size(); i++) {
			int dir = pipe[map[r][c]][i];
			int nxtr = r + dirr[dir];
			int nxtc = c + dirc[dir];

			if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < m) {
				if (dir == 0) {
					if (map[nxtr][nxtc] == 1 || map[nxtr][nxtc] == 2 || map[nxtr][nxtc] == 5 || map[nxtr][nxtc] == 6) {
						if (!visit[nxtr][nxtc]) {
							if (d + 1 <= time) {
								cnt++;
								visit[nxtr][nxtc] = true;
								q.push(node(nxtr, nxtc, d + 1));
							}
						}
					}
				}
				else if (dir == 1) {
					if (map[nxtr][nxtc] == 1 || map[nxtr][nxtc] == 2 || map[nxtr][nxtc] == 4 || map[nxtr][nxtc] == 7) {
						if (!visit[nxtr][nxtc]) {
							if (d + 1 <= time) {
								cnt++;
								visit[nxtr][nxtc] = true;
								q.push(node(nxtr, nxtc, d + 1));
							}
						}
					}
				}
				else if (dir == 2) {
					if (map[nxtr][nxtc] ==  1 || map[nxtr][nxtc] == 3 || map[nxtr][nxtc] == 4 || map[nxtr][nxtc] == 5) {
						if (!visit[nxtr][nxtc]) {
							if (d + 1 <= time) {
								cnt++;
								visit[nxtr][nxtc] = true;
								q.push(node(nxtr, nxtc, d + 1));
							}
						}
					}
				}
				else if (dir == 3) {
					if (map[nxtr][nxtc] == 1 || map[nxtr][nxtc] == 3 || map[nxtr][nxtc] == 6 || map[nxtr][nxtc] == 7) {
						if (!visit[nxtr][nxtc]) {
							if (d + 1 <= time) {
								cnt++;
								visit[nxtr][nxtc] = true;
								q.push(node(nxtr, nxtc, d + 1));
							}
						}
					}
				}
			}
		}

	}
	return cnt;
}
void makepipe() {
	pipe[1].push_back(0);
	pipe[1].push_back(1);
	pipe[1].push_back(2);
	pipe[1].push_back(3);

	pipe[2].push_back(0);
	pipe[2].push_back(1);
	
	pipe[3].push_back(2);
	pipe[3].push_back(3);

	pipe[4].push_back(0);
	pipe[4].push_back(3);
	
	pipe[5].push_back(3);
	pipe[5].push_back(1);

	pipe[6].push_back(2);
	pipe[6].push_back(1);

	pipe[7].push_back(0);
	pipe[7].push_back(2);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;	
	cin >> t;
	makepipe();
	for (int test = 1; test <= t; test++) {
		cin >> n >> m >> sr >> sc >> time;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> map[i][j];
		answer = bfs();
		cout << "#" << test << " " << answer << "\n";
	}
	

	return 0;
}