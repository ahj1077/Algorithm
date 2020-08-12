#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int n, m, nowx = 1000000, nowy = 1000000;
string oper;
int xarr[2000001];
int yarr[2000001];

vector<pair<int, int>> nodes;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xarr[1000000 + x]++;
		yarr[1000000 + y]++;
		nodes.push_back({ 1000000 + x,1000000 + y });
	}
	for (int i = 1999999; i >= 0; i--) {
		xarr[i] = xarr[i + 1] + xarr[i];
		yarr[i] = yarr[i + 1] + yarr[i];
	}

	long long total = 0;
	for (int j = 0; j < nodes.size(); j++) {
		total += abs(nowx - nodes[j].first) + abs(nowy - nodes[j].second);
	}

	cin >> oper;

	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == 'S') {
			//ºÏ
			nowy++;
			total -= yarr[nowy];
			total += (nodes.size() - yarr[nowy]);
		}
		else if (oper[i] == 'I') {
			//µ¿
			nowx++;
			total -= xarr[nowx];
			total += (nodes.size() - xarr[nowx]);
		}
		else if (oper[i] == 'J') {
			//³²
			total += yarr[nowy];
			total -= (nodes.size() - yarr[nowy]);
			nowy--;
		}
		else {
			//¼­
			total += xarr[nowx];
			total -= (nodes.size() - xarr[nowx]);
			nowx--;
		}

		cout << total << "\n";
	}


	return 0;
}