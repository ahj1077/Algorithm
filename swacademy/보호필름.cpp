#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;
int answer= 987654321;
int d, w, k;
bool map[13][20];
int setdrug[13];

void check(int setnum) {
	bool cpy[13][20];
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			cpy[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < d; i++) {
		if (setdrug[i] == 1) {
			for (int j = 0; j < w; j++) {
				cpy[i][j] = 0;
			}
		}
		else if (setdrug[i] == 2) {
			for (int j = 0; j < w; j++) {
				cpy[i][j] = 1;
			}
		}
	}

	bool pass = true;

	for (int i = 0; i < w; i++) {
		int cur = cpy[0][i];
		int cnt = 1;

		bool ok = false;
		for (int j = 1; j < d; j++) {
			if (cpy[j][i] == cur) {
				cnt++;
			}
			else {
				cur = cpy[j][i];
				cnt = 1;
			}

			if (cnt == k) {
				ok = true;
				break;
			}
		}

		if (!ok) {
			pass = false;
			break;
		}
	}

	if (pass) {
		answer = setnum;
	}
}

void set(int setnum, int depth, int start) {
	if (setnum == depth) {
		check(setnum);
		return;
	}

	for (int i = start; i < d; i++) {
		if (setdrug[i] == 0) {
			setdrug[i] = 1; // a약품
			set(setnum, depth + 1, i);

			if (answer != 987654321) 
				break;
			
			setdrug[i] = 2; // b 약품
			set(setnum, depth + 1, i);
			setdrug[i] = 0;

			if (answer != 987654321)
				break;
		}
	}
}

void init() {
	answer = 987654321;
	for (int i = 0; i < d; i++) 
		setdrug[i] = 0;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> d >> w >> k;
		init();

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i <= d; i++) {
			set(i, 0 , 0);
			if (answer != 987654321)
				break;
		}


		cout << "#" << t << " " << answer << "\n";
	}
	


	return 0;
}
