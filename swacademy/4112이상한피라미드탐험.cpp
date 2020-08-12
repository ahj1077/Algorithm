#include<iostream>
#include<algorithm>

using namespace std;

int answer, a,b;
int arr[10001];

void init() {
	int num = 1;
	int cnt = 0;
	for (int i = 1; i <= 10000; i++) {
		arr[i] = num;
		cnt++;
		if (cnt == num) {
			num++;
			cnt = 0;
		}
	}
}

void go(int num1, int num2) {
	int gap = arr[num1] - arr[num2];
	int left = num2;
	int addnum = arr[num2];

	for (int i = 0; i < gap; i++) {
		left += (addnum++);
	}

	int right = num2;
	addnum = arr[num2] + 1;
	for (int i = 0; i < gap; i++) {
		right += (addnum++);
	}

	if (num1 < left) {
		answer = gap + left - num1;
	}
	else if (num1 > right) {
		answer = gap + num1 - right;
	}
	else {
		answer = gap;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	init();

	for (int test = 1; test <= t; test++) {
		answer = 0;
		cin >> a >> b;

		if (arr[a] == arr[b]) 
			answer = abs(a - b);
		else {
			if (arr[a] > arr[b]) go(a, b);
			else go(b, a);
		}
		cout << "#" << test << " " << answer << "\n";
	}

	return 0;
}