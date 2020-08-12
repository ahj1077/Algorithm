#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int num1, num2;

bool visit[10000];

void bfs() {
	queue<pair<int, string>> q;
	q.push({num1, ""});
	visit[num1] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string oper = q.front().second;
		q.pop();

		if (num == num2) {
			cout << oper << "\n";
			break;
		}

		int d = (num * 2) % 10000;
		if (!visit[d]) {
			visit[d] = true;
			q.push({ d, oper + "D" });
		}

		int s = num - 1;
		if (s == 0) s = 9999;
		if (!visit[s]) {
			visit[s] = true;
			q.push({ s,oper + "S" });
		}

		int shiftval = num / 1000;
		int l = (num % 1000) * 10 + shiftval;
		if (!visit[l]) {
			visit[l] = true;
			q.push({ l, oper + "L" });
		}

		shiftval = num % 10;
		int r = (num / 10) + (shiftval * 1000);
		if (!visit[r]) {
			visit[r] = true;
			q.push({ r, oper + "R" });
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> num1 >> num2;
		bfs();

		for (int i = 0; i < 10000; i++)
			visit[i] = false;
	}

	
	return 0;
}