#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, k;
queue<pair<int, int>> q;
bool visit[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	visit[n] = true;
	q.push({ n, 0 });

	while (!q.empty()) {
		int pos = q.front().first;
		int t = q.front().second;
		q.pop();

		if (pos == k) {
			cout << t << "\n";
			return 0;
		}
		int nxtpos = pos - 1;
		if (nxtpos >=0 && nxtpos <= 100000 && !visit[nxtpos]) {
			visit[nxtpos] = true;
			q.push({ nxtpos, t + 1 });
		}
		
		nxtpos = pos + 1;
		if (nxtpos >= 0 && nxtpos <= 100000 && !visit[nxtpos]) {
			visit[nxtpos] = true;
			q.push({ nxtpos,t + 1 });
		}

		nxtpos = pos * 2;
		if (nxtpos >= 0 && nxtpos <= 100000 && !visit[nxtpos]) {
			visit[nxtpos] = true;
			q.push({ nxtpos,t + 1 });
		}
	}
	return 0;
}