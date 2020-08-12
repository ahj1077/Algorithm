#include<iostream>
#include<string>
#include<vector>
#include<queue>


using namespace std;




bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	int m = key[0].size();
	int n = lock[0].size();
	
	int padding_size = m - 1;
	int paddedlock[60][60];
	int hole = 0;

	for (int i = 0; i < 2 * (m - 1) + n; i++) {
		for (int j = 0; j < 2 * (m - 1) + n; j++) {
			paddedlock[i][j] =  -1;
		}
	}

	for (int i = m - 1; i < m - 1 + n; i++) {
		for (int j = m - 1; j < m - 1 + n; j++) {
			if (lock[i - m + 1][j - m + 1] == 0) hole++;
			paddedlock[i][j] = lock[i - m + 1][j - m + 1];
		}
	}
	
	for (int sr = 0; sr < m - 1 + n; sr++) {
		for (int sc = 0; sc < m - 1 + n; sc++) {
			int cnt = 0;
			bool ok = true;

			for (int i = 0; i < m & ok; i++) {
				for (int j = 0; j < m; j++) {
					if (paddedlock[sr + i][sc + j] == 1 && key[i][j] == 1) {
						ok = false;
						break;
					}
					else if (paddedlock[sr + i][sc + j] == 0 && key[i][j] == 1) {
						cnt++;
					}
				}
			}

			if (cnt == hole) ok = true;
			else ok = false;

			if (ok) return true;
		}
	}


	int turn90[20][20];
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			turn90[j][m - 1 - i] = key[i][j];
	
	for (int sr = 0; sr < m - 1 + n; sr++) {
		for (int sc = 0; sc < m - 1 + n; sc++) {
			int cnt = 0;
			bool ok = true;

			for (int i = 0; i < m & ok; i++) {
				for (int j = 0; j < m; j++) {
					if (paddedlock[sr + i][sc + j] == 1 && turn90[i][j] == 1) {
						ok = false;
						break;
					}
					else if (paddedlock[sr + i][sc + j] == 0 && turn90[i][j] == 1) {
						cnt++;
					}
				}
			}

			if (cnt == hole) ok = true;
			else ok = false;
			if (ok) return true;
		}
	}
	int turn180[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			turn180[j][m - 1 - i] = turn90[i][j];

	for (int sr = 0; sr < m - 1 + n; sr++) {
		for (int sc = 0; sc < m - 1 + n; sc++) {
			int cnt = 0;
			bool ok = true;

			for (int i = 0; i < m & ok; i++) {
				for (int j = 0; j < m; j++) {
					if (paddedlock[sr + i][sc + j] == 1 && turn180[i][j] == 1) {
						ok = false;
						break;
					}
					else if (paddedlock[sr + i][sc + j] == 0 && turn180[i][j] == 1) {
						cnt++;
					}
				}
			}

			if (cnt == hole) ok = true;
			else ok = false;
			if (ok) return true;
		}
	}
	int turn270[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			turn270[j][m - 1 - i] = turn180[i][j];
	for (int sr = 0; sr < m - 1 + n; sr++) {
		for (int sc = 0; sc < m - 1 + n; sc++) {
			int cnt = 0;
			bool ok = true;

			for (int i = 0; i < m & ok; i++) {
				for (int j = 0; j < m; j++) {
					if (paddedlock[sr + i][sc + j] == 1 && turn270[i][j] == 1) {
						ok = false;
						break;
					}
					else if (paddedlock[sr + i][sc + j] == 0 && turn270[i][j] == 1) {
						cnt++;
					}
				}
			}

			if (cnt == hole) ok = true;
			else ok = false;
			if (ok) return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> k, l;
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);
	k.push_back(v1);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);
	k.push_back(v2);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(1);
	v3.push_back(1);
	k.push_back(v3);

	vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(1);
	l.push_back(v4);

	vector<int> v5;
	v5.push_back(1);
	v5.push_back(1);
	v5.push_back(0);
	l.push_back(v5);

	vector<int> v6;
	v6.push_back(1);
	v6.push_back(0);
	v6.push_back(1);
	l.push_back(v6);

	bool ok = solution(k,l);
	cout << ok << "\n";
	return 0;
}