#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int parent[100001][18];
bool visit[100001];
int depth[100001];
vector<int> adlist[100001];

void dfs(int node, int d) {
	for (int i = 0; i < adlist[node].size(); i++) {
		if (!visit[adlist[node][i]]) {
			visit[adlist[node][i]] = true;
			parent[adlist[node][i]][0] = node;
			depth[adlist[node].at(i)] = d + 1;
			dfs(adlist[node][i], d + 1);
		}
	}
}

void makedp() {
	for (int i = 1; i <= n; i++) {
		for (int k = 1; parent[i][k - 1] != 0; k++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
}

int getLCA(int v1,int v2) {
	int tmp1, tmp2;
	if (depth[v1] < depth[v2]) {
		tmp1 = v1;
		tmp2 = v2;
	}
	else {
		tmp1 = v2;
		tmp2 = v1;
	}

	for (int i = 17; i >= 0; i--) {
		if (depth[parent[tmp2][i]] >= depth[tmp1]) {
			tmp2 = parent[tmp2][i];
		}
	}
	if (tmp1 == tmp2) 
		return tmp1;
	for (int i = 17; i >= 0; i--) {
		if (parent[tmp1][i] != parent[tmp2][i]) {
			tmp1 = parent[tmp1][i];
			tmp2 = parent[tmp2][i];
		}
	}
	return parent[tmp1][0];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	parent[1][0] = 0;
	depth[0] = -1;
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adlist[v1].push_back(v2);
		adlist[v2].push_back(v1);
	}

	cin >> m;

	visit[1] = true;
	dfs(1, 0);

	makedp();

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		cout << getLCA(v1, v2) << "\n";
	}


	return 0;
}