#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int g, p;
int parent[100001];

int find(int gi) {

	if (parent[gi] == gi) 
		return gi;
	
	return parent[gi] = find(parent[gi]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> g;
	cin >> p;

	int answer = 0;

	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
	bool ok = true;

	for (int i = 1; i <= p; i++) {
		int gi;
		cin >> gi;

		if (ok) {
			int gate = find(gi);
			if (gate == 0)
				ok = false;
			else {
				answer++;
				parent[gate] = gate - 1;
			}
		}
	}

	cout << answer << "\n";
	return 0;
}