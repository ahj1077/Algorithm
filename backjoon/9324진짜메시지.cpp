#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int cnt[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string m;
		cin >> m;
		
		bool ok = true;

		for (int i = 0; i < m.size(); i++) {
			if (cnt[m[i] - 'A'] == 2) {
				cnt[m[i] - 'A'] = 0;
				if (i + 1 < m.size() && m[i + 1] == m[i]) {
					i++;
				}
				else {
					ok = false;
					break;
				}
			}
			else {
				cnt[m[i] - 'A']++;
			}
		}

		if (ok)
			cout << "OK\n";
		else
			cout << "FAKE\n";

		for (int i = 0; i < 26; i++)
			cnt[i] = 0;
	}
	
	
	return 0;
}