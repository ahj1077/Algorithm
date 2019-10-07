#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<stack>

using namespace std;
int answer;
int n;
int map[10][10];
int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };


class person {
public:
	int step;
	int dtime;
	int inQtime;

	person(int dt) {
		step = 0;
		dtime = dt;
		inQtime = 0;
	}
};


deque<person> q1;
deque<person> q2;
vector<pair<int, int>> p;
vector<pair<int, int>> s;

bool cmp(person p1, person p2) {
	return p1.dtime < p2.dtime;
}

void check(int bit) {
	q1.clear();
	q2.clear();

	for (int i = 0; i < p.size(); i++) {
		if ((bit & (1 << i)) == (1 << i)) {
			int dtime = abs(s[1].first - p[i].first) + abs(s[1].second - p[i].second);
			q2.push_back(person(dtime));
		}
		else {
			int dtime = abs(s[0].first - p[i].first) + abs(s[0].second - p[i].second);
			q1.push_back(person(dtime));	
		}
	}

	sort(q1.begin(), q1.end(), cmp);
	sort(q2.begin(), q2.end(), cmp);
	
	deque<person> instair;
	queue<person> w1;
	queue<person> w2;

	int q1time = 0;
	int q2time = 0;

	if (!q1.empty()) {
		int stime = map[s[0].first][s[0].second];


		for (int time = q1.front().dtime; true; time++) {
			if (q1.empty() && w1.empty() && instair.empty()) {
				q1time = time;
				break;
			}
			
			//기다렸던사람 계단으로
			while (!w1.empty() && instair.size() < 3) {
				instair.push_back(w1.front());
				w1.pop();
			}

			//다른 사람 계단입구 도착
			for (int i = 0; true; i++) {
				if (!q1.empty() && time == q1.front().dtime) {
					w1.push(q1.front());
					q1.pop_front();
				}
				else break;
			}

			//계단 1칸씩 내려감
			for (int i = 0; i < instair.size(); i++) {
				instair[i].step++;
				if (instair[i].step == stime) {
					instair.pop_front();
					i--;
				}
			}
		}
	}

	if (!q2.empty()) {
		instair.clear();

		int stime = map[s[1].first][s[1].second];

		for (int time = q2.front().dtime; true; time++) {
			if (q2.empty() && w2.empty() && instair.empty()) {
				q2time = time;
				break;
			}

			//기다렸던사람 계단으로
			while (!w2.empty() && instair.size() < 3) {
				instair.push_back(w2.front());
				w2.pop();
			}

			//다른 사람 계단입구 도착
			for (int i = 0; true; i++) {
				if (!q2.empty() && time == q2.front().dtime) {
					w2.push(q2.front());
					q2.pop_front();
				}
				else break;
			}

			//계단 1칸씩 내려감
			for (int i = 0; i < instair.size(); i++) {
				instair[i].step++;
				if (instair[i].step == stime) {
					instair.pop_front();
					i--;
				}
			}
		}
	}
	q1time = max(q1time, q2time);
	answer = min(answer, q1time);
	
}

void dfs(int d,int bit) {
	if (d == p.size()) {
		check(bit);
		return;
	}

	dfs(d + 1, bit);
	dfs(d + 1, bit | (1 << d));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		answer = 987654321;
		s.clear();
		p.clear();

		int pnum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					map[i][j] = pnum++;
					p.push_back(pair<int, int>(i, j));
				}
				else if (map[i][j] > 1) {
					s.push_back(pair<int, int>(i, j));
				}
			}
		}

		dfs(0, 0);

		cout <<"#"<< t + 1 <<" "<< answer << "\n";
	}

	


	return 0;
}