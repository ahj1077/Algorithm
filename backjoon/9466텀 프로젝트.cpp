#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#define IN 0
#define NOTIN 1
#define OTHER 2

using namespace std;

int t, n;
int cycle_num = -1;
int student[100001];
int inCycle[100001];
bool visit[100001];

void dfs(const int start, int num, int depth) {

	if (inCycle[student[num]] != OTHER) {
		inCycle[num] = NOTIN;
		return;
	}

	if (!visit[student[num]]) {
		visit[student[num]] = true;
		dfs(start, student[num], depth + 1);

		if (cycle_num != -1) {
			inCycle[num] = IN;
			if (num == cycle_num) {
				cycle_num = -1;
				visit[student[num]] = false;
				return;
			}
		}
		else {
			inCycle[num] = NOTIN;
		}
		visit[student[num]] = false;
	}
	else {
		//사이클 생성
		cycle_num = student[num];
		inCycle[num] = IN;
		if (cycle_num == num) cycle_num = -1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		cycle_num = -1;

		for (int i = 1; i <= n; i++) {
			cin >> student[i];
			inCycle[i] = OTHER;
		}

		for (int i = 1; i <= n; i++) {
			if (inCycle[i] == OTHER) {
				visit[i] = true;
				dfs(i, i, 0);
				visit[i] = false;
			}
		}

		int total = 0;
		for (int i = 1; i <= n; i++) {
			if (inCycle[i] == NOTIN) total++;
		}
		cout << total << "\n";
	}

	return 0;

}
