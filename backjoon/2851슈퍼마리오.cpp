#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int answer;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool ok = true;

	for (int i = 0; i < 10; i++) {
		int s;
		cin >> s;

		if (ok) {
			if (answer + s > 100) {
				if (100 - answer >= answer + s - 100) {
					answer = answer + s - 100;
				}
				ok = false;
			}
			else {
				answer += s;
			}
		}
	}

	cout << answer << "\n";
	
	return 0;
}