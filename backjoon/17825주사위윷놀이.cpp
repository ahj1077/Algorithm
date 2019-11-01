#include<iostream>
#include <string>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#define END 33

using namespace std;
const int val[34] = { 0,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,22,24,26,27,28,30,35,0 };
int player[5] = {0,1,1,1,1};
vector<int> dice;
int answer = 0;

class node {
public:
	bool blue;
	int score;
	int idx;
	int nxtredidx;
	int nxtblueidx;

	node() {}
	node(bool b, int i,int s,int nri,int nbi) : blue(b), score(s), idx(i), nxtredidx(nri), nxtblueidx(nbi){}
};

node n[34];

void makemap() {
	for (int i = 1; i <= 33; i++) {
		bool blue = false;
		int score = val[i];
		int nxtredidx = -1;
		int nxtblueidx = -1;

		if (i == 6) {
			nxtredidx = 7;
			nxtblueidx = 22;
			blue = true;
		}
		else if (i == 11) {
			nxtredidx = 12;
			nxtblueidx = 26;
			blue = true;
		}
		else if (i == 16) {
			nxtredidx = 17;
			nxtblueidx = 30;
			blue = true;
		}
		else if (i == 21) {
			nxtredidx = END;
			nxtblueidx = END;
		}
		else if (i >= 22 && i <= 24) {
			nxtblueidx = i + 1;
		}
		else if (i == 26) {
			nxtblueidx = 27;
		}
		else if (i == 27)
			nxtblueidx = 25;
		else if (i == 28) {
			nxtblueidx = 25;
		}
		else if (i >= 29 && i <= 30) {
			nxtblueidx = i - 1;
		}
		else if (i == 25)
			nxtredidx = 31;
		else if (i == 31)
			nxtredidx = 32;
		else if (i == 32)
			nxtredidx = 21;
		else
			nxtredidx = i + 1;

		n[i] = node(blue, i, score, nxtredidx, nxtblueidx);
	}
}

int nxtnode(int pnum,int num, int p[5], bool blue) {
	int now = p[pnum];

	if (now == END)
		return -1;

	while (num--) {
		if (blue) {
			if (n[now].nxtblueidx != -1) {
				now = n[now].nxtblueidx;
			}
			else if (n[now].nxtredidx != -1) {
				now = n[now].nxtredidx;
			}
		}
		else {
			if (n[now].idx == END)
				return now;

			if (n[now].nxtredidx != -1) {
				now = n[now].nxtredidx;
			}
			else if(n[now].nxtblueidx != -1){
				now = n[now].nxtblueidx;
			}
		}
	}


	for (int i = 1; i <= 4; i++) {
		if (p[i] == now) 
			return -1;
	}
	return now;
}

void dfs(int depth, int total,int p[5]) {
	if (depth == 10) {
		answer = max(answer, total);
		return;
	}
	int position[5];
	for (int i = 1; i <= 4; i++)
		position[i] = p[i];

	//1번말 이동
	int nxt = nxtnode(1, dice[depth], position, n[position[1]].blue);
	if (nxt != -1) {
		int pnow = position[1];
		position[1] = nxt;
		dfs(depth + 1, total + n[nxt].score, position);
		position[1] = pnow;
	}
	//2번말 이동
	nxt = nxtnode(2, dice[depth], position, n[position[2]].blue);
	if (nxt != -1) {
		int pnow = position[2];
		position[2] = nxt;
		dfs(depth + 1, total + n[nxt].score, position);
		position[2] = pnow;
	}
	//3번말 이동
	nxt = nxtnode(3, dice[depth], position, n[position[3]].blue);
	if (nxt != -1) {
		int pnow = position[3];
		position[3] = nxt;
		dfs(depth + 1, total + n[nxt].score, position);
		position[3] = pnow;
	}
	//4번말 이동
	nxt = nxtnode(4, dice[depth], position, n[position[4]].blue);
	if (nxt != -1) {
		int pnow = position[4];
		position[4] = nxt;
		dfs(depth + 1, total + n[nxt].score, position);
		position[4] = pnow;
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	makemap();

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		dice.push_back(num);
	}

	dfs(0,0, player);

	cout << answer << "\n";
	return 0;
}
