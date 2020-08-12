#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int m, n;
bool map[100][100];
bool air[100][100];
bool cheese[100][100];
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };

queue<pair<int, int>> airq;
queue<pair<int, int>> nxtairq;
queue<pair<int, int>> cheeseq;
queue<pair<int, int>> cheesenxtq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int cheeses = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j]) cheeses++;
		}
	}
	airq.push({ 0,0 });
	air[0][0] = true;

	bool ok = false;

	for (int t = 0; !ok; t++) {

		while (!airq.empty()) {
			int r = airq.front().first;
			int c = airq.front().second;
			airq.pop();

			for (int i = 0; i < 4; i++) {
				int nxtr = r + dirr[i];
				int nxtc = c + dirc[i];

				if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < m) {
					if (!map[nxtr][nxtc] && !air[nxtr][nxtc]) {
						air[nxtr][nxtc] = true;
						airq.push({ nxtr,nxtc });
					}
					else if (map[nxtr][nxtc] && !cheese[nxtr][nxtc]) {
						cheese[nxtr][nxtc] = true;
						cheeseq.push({ nxtr,nxtc });
					}
				}
			}
		}

		while (!cheeseq.empty()) {
			int r = cheeseq.front().first;
			int c = cheeseq.front().second;
			cheeseq.pop();

			int cnt = 0;

			for (int i = 0; i < 4; i++) {
				int nxtr = r + dirr[i];
				int nxtc = c + dirc[i];

				if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < m) {
					if (air[nxtr][nxtc]) cnt++;
				}
			}
			if (cnt > 1) {
				cheesenxtq.push({ r,c });
			}
			else {
				cheese[r][c] = false;
			}
		}

		while (!cheesenxtq.empty()) {
			int r = cheesenxtq.front().first;
			int c = cheesenxtq.front().second;
			cheesenxtq.pop();

			map[r][c] = false;
			air[r][c] = true;
			cheeses--;
			if (cheeses == 0) {
				cout << t + 1 << "\n";
				ok = true;
				break;
			}
			airq.push({ r,c });
		}


	}

	
	return 0;
}