#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, m, t, answer1=987654321, answer2=987654321;
int gram_r, gram_c, gram_d;
int map[100][100];
bool gram = false;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
class node {
public:
	int r;
	int c;
	int d;
	node(int rr, int cc, int dd) :r(rr), c(cc), d(dd) {}
};

queue<node> q;
bool visit[100][100];

void bfs() {

	q.push(node(0, 0, 0));

	visit[0][0] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		if (r == n - 1 && c == m - 1) {
			answer1 = d;
			return;
		}

		if (d > t) return;

		for (int i = 0; i < 4; i++) {
			int nxtr = r + dirr[i];
			int nxtc = c + dirc[i];

			if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < m) {
				if (map[nxtr][nxtc] != 1 && !visit[nxtr][nxtc]) {
					visit[nxtr][nxtc] = true;
					q.push(node(nxtr, nxtc, d + 1));

					if (map[nxtr][nxtc] == 2) {
						gram_d = d + 1;
						gram = true;
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				gram_r = i;
				gram_c = j;
			}

		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
	
	bfs();

	if (gram) 
		answer2 = gram_d + (n - 1 - gram_r) + (m - 1 - gram_c);
	
	if (gram) {
		if (answer1 > answer2)
			answer1 = answer2;
		if (answer1 <= t)
			cout << answer1 << "\n";
		else
			cout << "Fail\n";
	}
	else {
		if (answer1 == 987654321)
			cout << "Fail\n";
		else
			cout << answer1 << "\n";
	}
	

	return 0;
}