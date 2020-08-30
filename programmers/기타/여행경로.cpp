#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<map>

using namespace std;

int n;
bool f = false;

vector<vector<string>> ticket;
vector<string> answer;
vector<bool> visit;

void dfs(string node, int depth) {

	if (depth == n) {
		f = true;
		return;
	}


	for (int i = 0; i < ticket.size(); i++) {
		if (ticket[i][0] == node && !visit[i]) {
			visit[i]= true;
			answer.push_back(ticket[i][1]);
			dfs(ticket[i][1], depth + 1);
			if (f) return;
			answer.pop_back();
			visit[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	n = tickets.size();
	for (int i = 0; i < tickets.size(); i++) {
		visit.push_back(false);
	}

	sort(tickets.begin(), tickets.end());
	ticket = tickets;

	answer.push_back("ICN");
	dfs("ICN", 0);

	return answer;
}
