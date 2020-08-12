#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class node {
public:
	int r;
	int c;
	int num;
	int dir;
	node(int rr, int cc, int pnum, int pdir) :r(rr), c(cc), num(pnum), dir(pdir) {}
};

int n, m, k, answer;
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };
int returndir[4] = { 1,0,3,2 };
vector<node> v;

void move() {
	vector<node> nxtmap[100][100];

	for (int i = 0; i < v.size(); i++) {
		int r = v[i].r;
		int c = v[i].c;
		int num = v[i].num;
		int dir = v[i].dir;

		int nxtr = r + dirr[dir];
		int nxtc = c + dirc[dir];

		if (nxtr < 1 || nxtr >= n - 1 || nxtc < 1 || nxtc >= n - 1) {
			//벽에다 박음
			if(num / 2 > 0)
				nxtmap[nxtr][nxtc].push_back(node(nxtr, nxtc, num / 2, returndir[dir]));
		}
		else {
			nxtmap[nxtr][nxtc].push_back(node(nxtr, nxtc, num, dir));
		}		
	}
	v.clear();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nxtmap[i][j].size() > 1) {
				int nxtdir = 0;
				int max_val = 0;
				int total_num = 0;

				for (int k = 0; k < nxtmap[i][j].size(); k++) {
					total_num += nxtmap[i][j][k].num;
					if (max_val < nxtmap[i][j][k].num) {
						max_val = nxtmap[i][j][k].num;
						nxtdir = nxtmap[i][j][k].dir;
					}
				}
				v.push_back(node(i, j, total_num, nxtdir));
			}
			else if(nxtmap[i][j].size() == 1){
				v.push_back(nxtmap[i][j][0]);
			}
		}
	}
}

void init() {
	answer = 0;
	v.clear();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> n >> m >> k;
		init();
		for (int i = 0; i < k; i++) {
			int r, c, num, dir;
			cin >> r >> c >> num >> dir;
			v.push_back(node(r, c, num, dir - 1));
		}


		while (m--) {
			move();
		}

		for (int i = 0; i < v.size(); i++) 
			answer += v[i].num;
		
		cout << "#" << test << " " << answer << "\n";
	}
	return 0;
}