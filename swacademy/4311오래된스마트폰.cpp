#include<iostream>

#define NOTMAKED 100

using namespace std;

int n, o, m, w;
int answer = 0;
bool cantouch[10];
bool canoper[5];
int canmake[1000];
int maked[1000];

void dfs(int total, int depth) {
	if (depth >= m)
		return; 

	if (total == w) {
		if(answer > depth + 1)
			answer = depth + 1;
	}

	for (int i = 1; i < 1000; i++) {
		if (canmake[i] == NOTMAKED) continue;

		for (int j = 1; j < 5; j++) {
			if (!canoper[j]) continue;

			int nxttotal = total;

			if (j == 1) {
				nxttotal += i;
			}
			if (j == 2) {
				nxttotal -= i;
			}
			if (j == 3) {
				nxttotal *= i;
			}
			if (j == 4) {
				nxttotal /= i;
			}
			if (nxttotal < 0 || nxttotal >999) continue;
			if (maked[nxttotal] > depth + canmake[i] + 1) {
				maked[nxttotal] = depth + canmake[i] + 1;
				dfs(nxttotal, maked[nxttotal]);
			}
		}

	}
}


void init() {
	for (int i = 0; i < 10; i++) 
		cantouch[i] = false;
	for (int i = 0; i < 5; i++)
		canoper[i] = false;
	for (int i = 0; i < 1000; i++) {
		canmake[i] = NOTMAKED;
		maked[i] = NOTMAKED;
	}

	answer = NOTMAKED;
}

void maker(int num, int depth) {
	if (depth == 4) return;

	for (int i = 0; i < 10; i++) {
		if (!cantouch[i]) continue;

		int maked = num * 10 + i;

		if (maked < 0 || maked > 999) continue;

		if (canmake[maked] > depth + 1) {
			canmake[maked] = depth + 1;
			maker(maked, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> n >> o >> m;
		
		init();

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			cantouch[num] = true;
		}

		for (int i = 0; i < 10; i++) {
			if (!cantouch[i]) continue;
			canmake[i] = 1;
			maker(i, 1);
		}

		for (int i = 0; i < o; i++) {
			int oper;
			cin >> oper;
			canoper[oper] = true;
		}

		cin >> w;
		

		if (canmake[w] == NOTMAKED) {
			for (int i = 1; i < 1000; i++) {
				if (canmake[i] == NOTMAKED) continue;

				dfs(i, canmake[i]);
			}
		}
		else {
			answer = canmake[w];
		}

		if (answer == NOTMAKED) answer = -1;
		cout << "#"<<test<<" " << answer << "\n";
	}

	return 0;
}