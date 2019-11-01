#include<iostream>
#include <string>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

int n, m, t, x, d, k;
deque<int> circle[51];
bool ok = false;

void notfound() {
	double total = 0;
	double divider = 0;
	for (int circle_num = 1; circle_num <= n; circle_num++) {
		for (int idx = 0; idx < m; idx++) {
			if (circle[circle_num].at(idx) > 0) {
				total += circle[circle_num].at(idx);
				divider++;
			}
		}
	}

	if (divider > 0) {
		double mean = total / divider;
		for (int circle_num = 1; circle_num <= n; circle_num++) {
			for (int idx = 0; idx < m; idx++) {
				int val = circle[circle_num].at(idx);
				if (val > 0) {
					if(val < mean)
						circle[circle_num].at(idx)++;
					else if(val > mean)
						circle[circle_num].at(idx)--;
				}
				
			}
		}
	}
}
void dfs(int circle_num, int idx, int val, bool find) {

	//좌우 먼저 검사
	int nxtidx = idx - 1;
	if (nxtidx < 0) nxtidx = m - 1;
	if (circle[circle_num].at(nxtidx) == val) {
		circle[circle_num].at(idx) = 0;
		circle[circle_num].at(nxtidx) = 0;
		ok = true;
		dfs(circle_num, nxtidx, val, true);
	}
	
	nxtidx = idx + 1;
	if (nxtidx == m) nxtidx = 0;
	if (circle[circle_num].at(nxtidx) == val) {
		circle[circle_num].at(idx) = 0;
		circle[circle_num].at(nxtidx) = 0;
		ok = true;
		dfs(circle_num, nxtidx, val, true);
	}

	//상하 검사
	int nxt_circle = circle_num - 1;
	if (nxt_circle > 0) {
		if (circle[nxt_circle].at(idx) == val) {
			circle[circle_num].at(idx) = 0;
			circle[nxt_circle].at(idx) = 0;
			ok = true;
			dfs(nxt_circle, idx, val, true);
		}
	}

	nxt_circle = circle_num + 1;
	if (nxt_circle <= n) {
		if (circle[nxt_circle].at(idx) == val) {
			circle[circle_num].at(idx) = 0;
			circle[nxt_circle].at(idx) = 0;
			ok = true;
			dfs(nxt_circle, idx, val, true);
		}
	}
	
}

void findsame() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (circle[i].at(j) > 0) {
				dfs(i,j,circle[i].at(j),false);
			}
		}
	}
}
void rotate(int circle_num, int dir,int num) {
	if (dir == 0) {
		//시계방향
		for (int i = 1; i*circle_num <= n; i++) {
			queue<int> q;
			int nxt_circle = circle_num * i;
			for (int j = 0; j < num; j++) {
				q.push(circle[nxt_circle].back());
				circle[nxt_circle].pop_back();
			}
			for (int j = 0; j < num; j++) {
				circle[nxt_circle].push_front(q.front());
				q.pop();
			}
		}

	}
	else {
		//반시계방향
		for (int i = 1; i*circle_num <= n; i++) {
			queue<int> q;
			int nxt_circle = circle_num * i;
			for (int j = 0; j < num; j++) {
				q.push(circle[nxt_circle].front());
				circle[nxt_circle].pop_front();
			}
			for (int j = 0; j < num; j++) {
				circle[nxt_circle].push_back(q.front());
				q.pop();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> t;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int val;
			cin >> val;
			circle[i].push_back(val);
		}
	}


	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;
		rotate(x, d, k);
		ok = false;
		findsame();
		if (!ok) 
			notfound();
	}

	int total = 0;
	for (int circle_num = 1; circle_num <= n; circle_num++) {
		for (int idx = 0; idx < m; idx++) {
			if (circle[circle_num].at(idx) > 0) 
				total += circle[circle_num].at(idx);
		}
	}
	cout << total << "\n";
	return 0;
}
