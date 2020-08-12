#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;
int k,answer;
deque<bool> gear[4];
int score[4] = { 1,2,4,8 };
bool ok[4];

void rotate(int g, int dir) {

	if (g > 0) {
		if (gear[g].at(6) != gear[g - 1].at(2)) {
			if (!ok[g - 1]) {
				ok[g - 1] = true;
				rotate(g - 1, -dir);
			}
		}
	}

	if(g < 3){
		if (gear[g].at(2) != gear[g + 1].at(6)) {
			if (!ok[g + 1]) {
				ok[g + 1] = true;
				rotate(g + 1, -dir);
			}
		}
	}

	if (dir == 1) {
		gear[g].push_front(gear[g].back());
		gear[g].pop_back();
	}
	else {
		gear[g].push_back(gear[g].front());
		gear[g].pop_front();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int k;
		cin >> k;
		answer = 0;
		for (int i = 0; i < 4; i++) {
			ok[i] = false;
			gear[i].clear();
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				bool val;
				cin >> val;
				gear[i].push_back(val);
			}
		}

		for (int i = 0; i < k; i++) {
			int gear_num, dir;
			cin >> gear_num >> dir;
			for (int j = 0; j < 4; j++)
				ok[j] = false;
			ok[gear_num - 1] = true;
			rotate(gear_num - 1, dir);
		}
		for (int i = 0; i < 4; i++) {
			if (gear[i][0]) {
				answer += score[i];
			}
		}
		
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}