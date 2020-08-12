#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int map[50][50];
bool visit[50][50];
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = (s[j] - '0');
		}
	}

	int answer = 0;

	for (int h = 1; h < 9; h++) {
		init();

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (map[i][j] == h && !visit[i][j]) {
					visit[i][j] = true;
					queue<pair<int, int>> q;
					queue<pair<int, int>> fill;

					q.push({ i,j });
					fill.push({ i, j });
					bool ok = true;

					while (!q.empty()) {
						int r = q.front().first;
						int c = q.front().second;
						q.pop();

						if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
							ok = false;
						}

						for (int k = 0; k < 4; k++) {
							int nxtr = r + dirr[k];
							int nxtc = c + dirc[k];

							if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < m) {
								if (map[nxtr][nxtc] == map[r][c] && !visit[nxtr][nxtc]) {
									visit[nxtr][nxtc] = true;
									fill.push({ nxtr,nxtc });
									q.push({ nxtr,nxtc });
								}
								else if (map[nxtr][nxtc] < map[r][c]) {
									ok = false;
								}
							}
						}
					}

					if (ok) {
						while (!fill.empty()) {
							answer++;
							map[fill.front().first][fill.front().second]++;
							fill.pop();
						}
					}
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}