#include<iostream>
#include<algorithm>

using namespace std;

int answer = 0;
int n, k;
int dia_size[10001];
void go(){
	int total = 0;
	for (int i = 1; i <= 1 + k; i++) {
		total += dia_size[i];
	}

	answer = max(answer, total);

	for (int i = 2; i <= 10000 - k + 1; i++) {
		total -= dia_size[i - 1];
		total += dia_size[i + k];
		answer = max(answer, total);
	}
}
void init() {
	answer = 0;

	for (int i = 0; i < 10001; i++) {
		dia_size[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		init();
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			int sz;
			cin >> sz;
			dia_size[sz]++;
		}

		go();

		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}