#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> &p1, pair<int, double> &p2) {
	if (p1.second > p2.second) {
		return true;
	}
	else if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else
		return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	//스테이지에 도달한 사람 수
	int n[501];
	//도달했지만 클리어x한 사람 수
	int m[501];

	for (int i = 1; i < N + 1; i++) {
		n[i] = 0;
		m[i] = 0;
	}

	for (int i = 0; i < stages.size(); i++) {
		int tmp = stages[i];

		if (stages[i] == N + 1)
			tmp--;

		for (int j = 1; j <= tmp; j++) {
			n[j]++;
		}
	}

	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] == N + 1)
			continue;
		m[stages[i]]++;
	}

	pair<int, double> s[501];
	for (int i = 1; i <= N; i++) {
		s[i].first = i;

		if (n[i] == 0 || m[i] == 0) s[i].second = 0;
		else
			s[i].second = (double)m[i] / n[i];
	}

	sort(s + 1, s + N + 1, cmp);

	for (int i = 1; i <= N; i++) {
		answer.push_back(s[i].first);
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	vector<int> r;
	r.push_back(2);
	r.push_back(1);
	r.push_back(2);
	r.push_back(6);
	r.push_back(2);
	r.push_back(4);
	r.push_back(3);
	r.push_back(3);

	vector<int> a = solution(5, r);
	return 0;
}