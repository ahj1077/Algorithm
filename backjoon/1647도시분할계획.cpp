#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n, m;


class Line {
public:
	int node1;
	int node2;
	int val;

	Line(int _node1, int _node2, int _val):node1(_node1), node2(_node2), val(_val) {}
};


struct cmp {
	bool operator()(Line l1, Line l2){
		return l1.val > l2.val;
	}
};

priority_queue<Line,vector<Line>,cmp> lines;
vector<Line> selected;
vector<Line> adlist[100001];
int parent[100001], total;

int find(int node) {
	if (node == parent[node]) {
		return node;
	}

	return parent[node] = find(parent[node]);
}

void merge(Line line) {
	int p1 = find(line.node1);
	int p2 = find(line.node2);

	if (p1 != p2) {
		if (p1 > p2) {
			parent[p1] = p2;
		}
		else {
			parent[p2] = p1;
		}
		total += line.val;
		selected.push_back(line);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lines.push(Line(a, b, c));
	}

	while (!lines.empty() && selected.size() < n - 1) {
		Line line = lines.top();
		lines.pop();

		if (find(line.node1) != find(line.node2)) {
			merge(line);
		}
	}

	int answer = 987654321;

	for (int i = 0; i < selected.size(); i++) {
		answer = min(answer, total - selected[i].val);
	}

	cout << answer << "\n";
	return 0;

}
