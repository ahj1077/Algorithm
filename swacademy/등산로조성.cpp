#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<stack>

using namespace std;

int n, k;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
int map[8][8];
bool visit[8][8];
int answer = 0;
vector<pair<int, int>> top;

void dfs(int r, int c, int d, bool ok) {
	
	answer = max(answer, d);

	for (int i = 0; i < 4; i++) {
		int nxtr = r + dirr[i];
		int nxtc = c + dirc[i];

		if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < n) {
			if (map[r][c] > map[nxtr][nxtc]) {
				if (!visit[nxtr][nxtc]) {
					visit[nxtr][nxtc] = true;
					dfs(nxtr, nxtc, d + 1, ok);
					visit[nxtr][nxtc] = false;
				}
			}
			else if (!ok && map[nxtr][nxtc] - map[r][c] < k) {
				if (!visit[nxtr][nxtc]) {
					visit[nxtr][nxtc] = true;
					int tmp = map[nxtr][nxtc];
					map[nxtr][nxtc] = map[r][c] - 1;
					dfs(nxtr, nxtc, d + 1, true);
					map[nxtr][nxtc] = tmp;
					visit[nxtr][nxtc] = false;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> k;
		answer = 0;
		top.clear();

		int max_h = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				max_h = max(max_h, map[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == max_h)
					top.push_back(pair<int, int>(i, j));
			}
		}

		for (int j = 0; j < top.size(); j++){
			dfs(top[j].first, top[j].second, 1, false);
		}
		cout <<"#"<<t<<" "<<answer << "\n";
	}

	


	return 0;
}