#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

char Board[30][30];
bool ok[30][30];

void chk(int r,int c) {
	if (Board[r][c] == ' ') return;
	if (Board[r][c] != Board[r][c + 1]) return;
	if (Board[r][c] != Board[r + 1][c]) return;
	if (Board[r][c] != Board[r + 1][c + 1]) return;

	ok[r][c] = ok[r][c + 1] = ok[r + 1][c] = ok[r + 1][c + 1] = true;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < n; j++) {
			Board[i][j] = board[i][j];
		}
	}
	
	while (1) {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ok[i][j] = false;
			}
		}

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				chk(i, j);
			}
		}

		bool f = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ok[i][j]) {
					f = true;
					answer++;
					Board[i][j] = ' ';
				}
			}
		}

		if (!f) break;

		for (int i = 0; i < n; i++) {
			stack<char> stk;
			for (int j = 0; j < m; j++) {
				if (Board[j][i] != ' ')
					stk.push(Board[j][i]);
			}

			for (int j = m-1; j >= 0; j--) {
				if (stk.empty()) {
					Board[j][i] = ' ';
				}
				else {
					Board[j][i] = stk.top();
					stk.pop();
				}
			}
		}

	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> param = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

	solution(4,5,param);
	
	return 0;

}
