#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int k, w, h;
bool map[200][200];
int visit[200][200];
int dirr[12] = { -1,0,1,0,-2, -2, -1, 1, 2, 2, 1, -1};
int dirc[12] = { 0,1,0,-1,-1, 1, 2, 2, 1, -1, -2, -2};

class node {
public:
	int r;
	int c;
	int d;
	int jump;
	node(int rr, int cc, int dd, int jj) :r(rr), c(cc), d(dd), jump(jj) {}
};

void bfs() {
	queue<node> q;
	q.push(node(0, 0, 0, 0));
	visit[0][0] = 0;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		int jump = q.front().jump;
		q.pop();

		if (r == h - 1 && c == w - 1) {
			cout<<d<<"\n";
			break;
		}

		for (int i = 0; i < 12; i++) {
			
			if (i > 3 && jump > k - 1) continue;

			int nxtr = r + dirr[i];
			int nxtc = c + dirc[i];
			int nxtjump = jump;
			if (i > 3) nxtjump++;

			if (nxtr >= 0 && nxtr < h && nxtc >= 0 && nxtc < w) {
				if (!map[nxtr][nxtc] && (visit[nxtr][nxtc] == -1 || visit[nxtr][nxtc] > nxtjump)) {
					visit[nxtr][nxtc] = nxtjump;
					q.push(node(nxtr, nxtc, d + 1, nxtjump));
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
	
	bfs();
	
	return 0;
}