#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, k, m;

vector<int> hypertube[1001];
vector<int> link[100001];

bool visit[100001];

void bfs() {
	queue<pair<int,int>> q;
	q.push({1, 1});
	visit[1] = true;

	while (!q.empty()) {
		int station = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (station == n) {
			cout << depth << "\n";
			break;
		}

		for (int i = 0; i < link[station].size(); i++) {
			for (int j = 0; j < hypertube[link[station][i]].size(); j++) {
				int nxtstation = hypertube[link[station][i]][j];
				if (!visit[nxtstation]) {
					visit[nxtstation] = true;
					q.push({ nxtstation,depth + 1 });
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int num;
			cin >> num;
			hypertube[i].push_back(num);
			link[num].push_back(i);
		}
	}

	bfs();

	
	return 0;
}