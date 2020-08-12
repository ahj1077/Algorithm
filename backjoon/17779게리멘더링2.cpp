#include<iostream>
#include<algorithm>

using namespace std;

int n, answer = 987654321;
int map[20][20];
int group[20][20];
int person[5];

void make5sector(int x,int y, int d1,int d2) {
	int left = y;
	int right = y;
	for (int i = 0; i <= d1 + d2; i++) {
		for (int j = left; j <= right; j++) {
			group[x + i][j] = 5;
			person[4] += map[x + i][j];
		}
		if (i >= d1) left++;
		else left--;
		if (i >= d2) right--;
		else right++;
	}
}

void makesector(int x, int y ,int d1, int d2) {
	for (int i = 0; i < x + d1; i++) {
		for (int j = 0; j <= y; j++) {
			if (group[i][j] == 0) {
				group[i][j] = 1;
				person[0] += map[i][j];
			}
			else break;
		}
	}

	for (int i = n - 1; i >  y; i--) {
		for (int j = 0; j <= x + d2; j++) {
			if (group[j][i] == 0) {
				group[j][i] = 2;
				person[1] += map[j][i];
			}
			else break;
		}
	}

	for (int i = x + d1; i < n; i++) {
		for (int j = 0; j < y-d1+d2; j++) {
			if (group[i][j] == 0) {
				group[i][j] = 3;
				person[2] += map[i][j];
			}
			else break;
		}
	}

	for (int i = x + d2 + 1; i < n; i++) {
		for (int j = n - 1; j >= y-d1+d2; j--) {
			if (group[i][j] == 0) {
				group[i][j] = 4;
				person[3] += map[i][j];
			}
			else break;
		}
	}

	int min_val = person[0];
	int max_val = person[0];

	for (int i = 1; i < 5; i++) {
		if (person[i] < min_val) min_val = person[i];
		else if (person[i] > max_val) max_val = person[i];
	}

	answer = min(answer, max_val - min_val);
}
void clearPerson() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			group[i][j] = 0;

	for (int i = 0; i < 5; i++)
		person[i] = 0;
}

void center(int x, int y) {
	for (int d1 = 1; y - d1 >=0; d1++) {
		for (int d2 = 1; (x + d1 + d2 < n) && (y + d2 < n); d2++) {
			clearPerson();
			make5sector(x, y, d1, d2);
			makesector(x, y, d1, d2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			center(i, j);
		}
	}

	cout << answer << "\n";
	return 0;
}