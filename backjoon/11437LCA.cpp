#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int parent[50001];
bool visit[50001];
int depth[50001];
vector<int> adlist[50001];

void dfs(int node, int d) {
	for (int i = 0; i < adlist[node].size(); i++) {
		if (!visit[adlist[node][i]]) {
			visit[adlist[node][i]] = true;
			parent[adlist[node][i]] = node;
			depth[adlist[node].at(i)] = d + 1;
			dfs(adlist[node][i], d + 1);
		}
	}
}
int getLCA(int v1,int v2) {
	int tmp1 = v1, tmp2 = v2;

	if (depth[tmp1] > depth[tmp2]) {
		while (depth[tmp1] != depth[tmp2]) {
			tmp1 = parent[tmp1];
		}
	}
	else if (depth[tmp1] < depth[tmp2]) {
		while (depth[tmp1] != depth[tmp2]) {
			tmp2 = parent[tmp2];
		}
	}

	while (tmp1 != tmp2) {
		tmp1 = parent[tmp1];
		tmp2 = parent[tmp2];
	}

	return tmp1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	parent[1] = 1;
	depth[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adlist[v1].push_back(v2);
		adlist[v2].push_back(v1);
	}

	cin >> m;

	visit[1] = true;
	dfs(1, 0);


	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		cout << getLCA(v1, v2) << "\n";
	}


	return 0;
}