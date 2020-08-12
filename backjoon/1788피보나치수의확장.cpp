#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt;
	if (n >= 2) {
		cnt = 1;
		int f1 = 0;
		int f2 = 1;
		int f3 = 0;

		while (1) {
			cnt++;
			f3 = (f1 + f2) % 1000000000;
			f1 = f2;
			f2 = f3;

			if (cnt == n) {
				if (f3 < 0) cout << -1 << "\n";
				else cout << 1 << "\n";
				cout << abs(f3) << "\n";
				break;
			}
		}
	}
	else if(n < 0){
		cnt = 0;
		int f1 = 1;
		int f2 = 0;
		int f3 = 0;

		while (1) {
			cnt--;
			f3 = (f1 - f2) % 1000000000;
			f1 = f2;
			f2 = f3;

			if (cnt == n) {
				if (f3 < 0) cout << -1 << "\n";
				else if (f3 == 0) cout << 0 << "\n";
				else cout << 1 << "\n";

				cout << abs(f3) << "\n";
				break;
			}
		}
	}
	else {
		if (n == 0) cout << 0 << "\n";
		else cout << 1 << "\n";
		cout << n << "\n";
	}
	
	
	return 0;
}