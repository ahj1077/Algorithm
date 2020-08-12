#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int true_num;
bool truePerson[51];
bool trueParty[51];

queue<int> q;

vector<int> party[51]; // i번째 파티에 소속된 사람들 모음
vector<int> person[51]; // i번째 사람이 소속된 파티들 모음

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> true_num;

	for (int i = 0; i < true_num; i++) {
		int num;
		cin >> num;
		q.push(num);
		truePerson[num] = true;
	}

	for (int i = 1; i <= m; i++) {
		int person_num;
		cin >> person_num;

		for (int j = 0; j < person_num; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
			person[num].push_back(i);
		}
	}
	
	queue<int> truePartyQ;
	bool personinqueue[51];
	bool partyinqueue[51];

	for (int i = 0; i < 51; i++) {
		personinqueue[i] = false;
		partyinqueue[i] = false;
	}

	while (!q.empty()) {
		while (!q.empty()) {
			int trueperson = q.front();
			q.pop();

			personinqueue[trueperson] = true;

			for (int i = 0; i < person[trueperson].size(); i++) {
				int trueparty = person[trueperson][i];

				if (!partyinqueue[trueparty]) {
					partyinqueue[trueparty] = true;
					trueParty[trueparty] = true;
					truePartyQ.push(trueparty);
				}
			}
		}

		while (!truePartyQ.empty()) {
			int trueparty = truePartyQ.front();
			truePartyQ.pop();



			for (int i = 0; i < party[trueparty].size(); i++) {
				int trueperson = party[trueparty][i];
				if (!personinqueue[trueperson]) {
					personinqueue[trueperson] = true;
					q.push(trueperson);
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= m; i++) {
		if (!trueParty[i]) answer++;
	}

	cout << answer << "\n";
	
	return 0;
}