#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int answer[2] = {0,0};

bool map[10][10];
int dirr[4] = { -1,-1,1,1 };
int dirc[4] = { -1,1,1,-1 };

vector<pair<int, int>> v[2];

void go(int idx, int depth, bool cpy[][10], int f) {

	bool ok[10][10];

	for (int i = idx; i < v[f].size(); i++) {
		int r = v[f][i].first;
		int c = v[f][i].second;

		if (cpy[r][c]) {
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					ok[j][k] = cpy[j][k];

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					int nxtr = r + dirr[k] * j;
					int nxtc = c + dirc[k] * j;

					if (nxtr >= 0 && nxtr < n && nxtc >= 0 && nxtc < n) {
						ok[nxtr][nxtc] = false;
					}
				}
			}

			if(i + 1 < v[f].size())
				go(i + 1, depth + 1, ok, f);
			else {
				answer[f] = max(answer[f], depth + 1);
			}
		}
	}

	answer[f] = max(answer[f], depth);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				if ((i + j) % 2 == 0)
					v[0].push_back({ i,j });
				else
					v[1].push_back({ i,j });
			}
		}
	}

	go(0, 0, map, 0);
	go(0, 0, map, 1);

	cout << answer[0] + answer[1] << "\n";

	return 0;
}