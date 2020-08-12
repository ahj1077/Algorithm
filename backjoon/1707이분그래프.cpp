#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int v, e;

vector<int> adlist[20001];
vector<pair<int, int>> lines;
int visit[20001];
bool ok = true;

void bfs(int v) {
	queue<pair<int,int>> q;
	q.push({ v , 1});
	visit[v] = 1;

	while (!q.empty()) {
		int vv = q.front().first;
		int color = q.front().second;
		q.pop();

		for (int i = 0; i < adlist[vv].size(); i++) {
			if (visit[adlist[vv][i]] == 0) {
				visit[adlist[vv][i]] = -color;
				q.push({ adlist[vv][i] , -color});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> v >> e;

		lines.clear();
		for (int i = 1; i <= v; i++) {
			adlist[i].clear();
			visit[i] = 0;
			ok = true;
		}
		

		for (int i = 0; i < e; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			adlist[v1].push_back(v2);
			adlist[v2].push_back(v1);
			lines.push_back({ v1,v2 });
		}

		for (int i = 1; i <= v; i++) {
			if (visit[i] == 0) {
				bfs(i);
			}
		}

		for (int i = 0; i < lines.size(); i++) {
			if (lines[i].first != lines[i].second && visit[lines[i].first] == visit[lines[i].second]) {
				ok = false;
				break;
			}
		}

		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}