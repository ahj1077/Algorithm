#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;


int n, m; 
int pr, pc;
int dirr[4] = { -1,0,1,0 };
int dirc[4] = { 0,1,0,-1 };
char map[500][500];
int answer = 0;
int answer_dir = 0;
bool infinite = false;
bool loop = false;
bool update = false;

char dir[4] = { 'U','R','D','L' };

void shot(int r,int c, int dir, int cnt) {
	if (cnt > n*m) {
		loop = true;
		infinite = true;
		return;
	}

	if (map[r][c] == '/') {
		if (dir == 0) dir = 1;
		else if (dir == 1) dir = 0;
		else if (dir == 3) dir = 2;
		else if (dir == 2) dir = 3;
	}
	else if (map[r][c] == '\\') {
		if (dir == 0) dir = 3;
		else if (dir == 3) dir = 0;
		else if (dir == 2) dir = 1;
		else if (dir == 1) dir = 2;
	}


	int nxtr = r + dirr[dir];
	int nxtc = c + dirc[dir];

	if (nxtr < 0 || nxtr >= n || nxtc < 0 || nxtc >= m || map[nxtr][nxtc] == 'C') {
		if (answer <= cnt + 1) {
			answer = cnt + 1;
			update = true;
		}
		return;
	}

	shot(nxtr, nxtc, dir, cnt + 1);

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> pr >> pc;

	for (int i = 3; i >= 0; i--) {
		update = false;
		loop = false;
		shot(pr - 1, pc - 1, i, 0);
		

		if (update || loop) {
			answer_dir = i;
		}
	}
	
	if (!infinite) {
		cout <<dir[answer_dir]<<"\n"<<answer << "\n";
	}
	else {
		cout << dir[answer_dir] << "\n";
		cout << "Voyager\n";
	}
	return 0;
}