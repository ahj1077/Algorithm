#include<iostream>
#include<queue>


using namespace std;

int depth[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = 0;
	int d, n;
	cin >> d >> n;
	
	depth[0] = 2100000000;

	for (int i = 1; i <= d; i++) {
		cin >> depth[i];
		if (depth[i] > depth[i - 1])
			depth[i] = depth[i - 1];
	}

	int base = d;
	bool ok = true;
	int pizza;
	int pre_pizza = -1;
	int pizza_num = n;

	cin >> pizza;
	for (int i = base; i >= 1; i--) {
		if (depth[i] >= pizza) {
			base = i - 1;
			pre_pizza = pizza;
			pizza_num--;
			break;
		}
	}

	if (pizza_num < n) {
		for (int i = 1; i < n; i++) {
			cin >> pizza;
			
			if (pre_pizza >= pizza) {
				base--;
				pizza_num--;
				pre_pizza = pizza;
			}
			else {
				for (int j = base; j >= 1; j--) {
					if (depth[j] >= pizza) {
						base = j - 1;
						pizza_num--;
						pre_pizza = pizza;
						break;
					}
				}
			}
			if (pizza_num > base) {
				ok = false;
				break;
			}
		}
	}
	else ok = false;

	if (ok) cout << base + 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}