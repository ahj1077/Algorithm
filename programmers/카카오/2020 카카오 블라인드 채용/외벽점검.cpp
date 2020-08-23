#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int N;
vector<int> w;
vector<int> d;
int min_worker = 987654321;

bool isweak[200];
bool worker[8];

int findnxt(int cur, bool *chk) {
	for (int i = cur; i < cur + N; i++) {
		int cur_pos = i % N;

		if (isweak[cur_pos] && !chk[cur_pos]) {
			return cur_pos;
		}
	}
	return -1;
}

void dfs(int weak_pos, int worker_idx, int depth, bool *arr) {
	int pos = 0;
	bool chkarr[200];
	for (int i = 0; i < N; i++)
		chkarr[i] = arr[i];

	for (int i = w[weak_pos]; i <= w[weak_pos] + d[worker_idx]; i++) {
		int cur_pos = i % N;
		chkarr[cur_pos] = true;
		pos = cur_pos;
	}

	int nxtweak = findnxt(pos, chkarr);

	if (nxtweak == -1) {
		min_worker = min(min_worker, depth);
		return;
	}
	else {
		for (int j = 0; j < d.size(); j++) {
			if (!worker[j]) {
				worker[j] = true;
				dfs(nxtweak, j, depth + 1, chkarr);
				worker[j] = false;
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	w = weak;
	d = dist;
	N = n;

	for (int i = 0; i < weak.size(); i++) {
		isweak[weak[i]] = true;
	}
	bool chkarr[200];
	for (int i = 0; i < n; i++)
		chkarr[i] = false;

	for (int j = 0; j < weak.size(); j++) {
		for (int i = 0; i < dist.size(); i++) {
			worker[i] = true;
			dfs(j, i, 1, chkarr);
			worker[i] = false;
		}
	}

	if (min_worker == 987654321) return -1;
	else answer = min_worker;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(10);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	solution(12, v1, v2);

	return 0;
}