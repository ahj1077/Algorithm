#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n,answer;
int mymap[102][102];
int returndir[6][4];
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };

vector<pair<int, int>> wh[5];
map<pair<int, int>, pair<int, int>> hole;

void shot(int sr,int sc, int start_dir, int score) {
	int nowr = sr;
	int nowc = sc;

	int dir = start_dir;

	while (1) {
		int nxtr = nowr + dirr[dir];
		int nxtc = nowc + dirc[dir];

		if (mymap[nxtr][nxtc] == -1 || (sr == nxtr && sc == nxtc))
			break;

		if (mymap[nxtr][nxtc] == 0) {
			nowr = nxtr;
			nowc = nxtc;
		}
		else {
			if (mymap[nxtr][nxtc] >= 1 && mymap[nxtr][nxtc] <= 5) {
				nowr = nxtr;
				nowc = nxtc;
				dir = returndir[mymap[nxtr][nxtc]][dir];
				score++;
			}
			else {
				//¿úÈ¦
				map<pair<int, int>, pair<int, int>>::iterator iter;
				iter = hole.find({ nxtr,nxtc });
				nowr = iter->second.first;
				nowc = iter->second.second;
			}
		}
	}

	answer = max(answer, score);
}
void start(int sr, int sc) {
	for (int i = 0; i < 4; i++) {
		shot(sr, sc, i, 0);
	}
}

void makereturndir() {
	returndir[1][0] = 1;
	returndir[1][1] = 3;
	returndir[1][2] = 0;
	returndir[1][3] = 2;

	returndir[2][0] = 3;
	returndir[2][1] = 0;
	returndir[2][2] = 1;
	returndir[2][3] = 2;

	returndir[3][0] = 2;
	returndir[3][1] = 0;
	returndir[3][2] = 3;
	returndir[3][3] = 1;

	returndir[4][0] = 1;
	returndir[4][1] = 2;
	returndir[4][2] = 3;
	returndir[4][3] = 0;

	returndir[5][0] = 1;
	returndir[5][1] = 0;
	returndir[5][2] = 3;
	returndir[5][3] = 2;
}

void init() {
	answer = 0;
	hole.clear();
	for (int i = 0; i < 5; i++) {
		wh[i].clear();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	makereturndir();

	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n;
		init();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> mymap[i][j];
				if (mymap[i][j] >= 6 && mymap[i][j] <= 10) {
					wh[mymap[i][j] - 6].push_back({ i,j });
				}
			}
		}
		
		for (int i = 0; i < 5; i++) {
			if (wh[i].size() == 2) {
				hole.insert(pair<pair<int, int>, pair<int, int>>({ wh[i][0].first,wh[i][0].second }, { wh[i][1].first, wh[i][1].second }));
				hole.insert(pair<pair<int, int>, pair<int, int>>({ wh[i][1].first,wh[i][1].second }, { wh[i][0].first, wh[i][0].second }));
			}
			else continue;
		}

		for (int i = 0; i <= n + 1; i++) {
			mymap[0][i] = 5;
			mymap[n + 1][i] = 5;
		}
		for (int i = 0; i <= n + 1; i++) {
			mymap[i][0] = 5;
			mymap[i][n + 1] = 5;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mymap[i][j] == 0)
					start(i, j);
			}
		}
		cout << "#" << test << " " << answer << "\n";
	}
	

	return 0;
}