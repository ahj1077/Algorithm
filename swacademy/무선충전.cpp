#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;

int answer = 0;
int m, a;
vector<int> map[10][10];


vector<pair<int,int>> p1;
vector<pair<int,int>> p2;
int bc[9];

void setbc(int r,int c,int range,int bc_num) {

	int tmp = 0;
	for (int i = r - range; i <= r + range; i++) {
		for (int j = c - tmp; j <= c + tmp; j++) {
			if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				map[i][j].push_back(bc_num);
			}
		}
		if (i >= r) {
			tmp--;
		}
		else
			tmp++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		answer = 0;
		int p1r = 0, p1c = 0;
		int p2r = 9, p2c = 9;
		p1.push_back({ 0,0 });
		p2.push_back({9, 9});

		cin >> m >> a;
		for (int i = 0; i < m; i++) {
			int dir;
			cin >> dir;
			if (dir == 0) {
				p1.push_back({p1r,p1c});
			}
			else if (dir == 1) {
				p1.push_back({ --p1r, p1c });
			}
			else if (dir == 2) {
				p1.push_back({ p1r, ++p1c});
			}
			else if (dir == 3) {
				p1.push_back({ ++p1r,p1c });
			}
			else if (dir == 4) {
				p1.push_back({ p1r, --p1c});
			}
		}
		for (int i = 0; i < m; i++) {
			int dir;
			cin >> dir;
			if (dir == 0) {
				p2.push_back({ p2r, p2c });
			}
			else if (dir == 1) {
				p2.push_back({ --p2r, p2c });
			}
			else if (dir == 2) {
				p2.push_back({ p2r, ++p2c});
			}
			else if (dir == 3) {
				p2.push_back({ ++p2r, p2c });
			}
			else if (dir == 4) {
				p2.push_back({ p2r, --p2c});
			}
		}

		for (int i = 1; i <= a; i++) {
			int x, y, range, p;
			cin >> x >> y >> range >> p;
			bc[i] = p;
			setbc(y - 1,x - 1,range,i);
		}

		for (int i = 0; i <= m; i++) {
			p1r = p1[i].first;
			p1c = p1[i].second;

			p2r = p2[i].first;
			p2c = p2[i].second;

			if (!map[p1r][p1c].empty() && !map[p2r][p2c].empty()) {
				int max_power = 0;
				for (int j = 0; j < map[p1r][p1c].size(); j++) {
					for (int k = 0; k < map[p2r][p2c].size(); k++) {
						if (map[p1r][p1c][j] == map[p2r][p2c][k]) {
							max_power = max(max_power, bc[map[p1r][p1c][j]]);
						}
						else {
							max_power = max(max_power, bc[map[p1r][p1c][j]] + bc[map[p2r][p2c][k]]);
						}
					}
				}
				answer += max_power;
			}
			else if (!map[p1r][p1c].empty() && map[p2r][p2c].empty()) {
				int max_power = 0;
				for (int j = 0; j < map[p1r][p1c].size(); j++) {
					max_power = max(max_power, bc[map[p1r][p1c][j]]);
				}
				answer += max_power;
			}
			else if (map[p1r][p1c].empty() && !map[p2r][p2c].empty()) {
				int max_power = 0;
				for (int j = 0; j < map[p2r][p2c].size(); j++) {
					max_power = max(max_power, bc[map[p2r][p2c][j]]);
				}
				answer += max_power;
			}
			else {
				continue;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
	


	return 0;
}
