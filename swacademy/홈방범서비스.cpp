#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<stack>

using namespace std;
int answer;
int n, m;
int houses;
bool map[20][20];

void check(int r, int c) {
	for (int k = 1; pow(k, 2) + pow(k - 1, 2) <= houses * m; k++) {
		int h = 0;
		int left = c, right = c;

		for (int i = r - k + 1; i < r + k; i++) {
			if (i < 0) {
				left--;
				right++;
				continue;
			}
			else if (i >= n)
				break;

			for (int j = left; j <= right; j++) {
				if (j < 0)
					continue;

				else if (j >= n)
					break;

				if (map[i][j]) 
					h++;
			}

			if (i < r) {
				left--;
				right++;
			}
			else {
				left++;
				right--;
			}
		}

		if (pow(k, 2) + pow(k - 1, 2) <= m * h) {
			answer = max(answer, h);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> m;
		answer = 0;
		houses = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j]) houses++;
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				check(i,j);

		cout <<"#"<<t + 1<<" "<<answer << "\n";
	}

	


	return 0;
}