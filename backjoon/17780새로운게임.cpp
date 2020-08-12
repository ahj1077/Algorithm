#include<iostream>
#include<algorithm>
#include<stack>
#define W 0
#define R 1
#define B 2

using namespace std;

int n, k;
int map[12][12];
const int inverse_dir[5] = { 0, 2, 1, 4, 3 };
pair<int, int> player[10];

stack<pair<int,int>> stk[12][12];

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (stk[i][j].size() >= 4)
				return true;
		}
	}

	return false;
}
void move() {
	for (int i = 0; i < k; i++) {
		int pr = player[i].first;
		int pc = player[i].second;

		stack<pair<int, int>> move_players;
		
		bool ok = true;
		while (!stk[pr][pc].empty()) {
			move_players.push(stk[pr][pc].top());
			stk[pr][pc].pop();

			if (move_players.top().first == i) {
				if(stk[pr][pc].empty())
					break;
				else {
					ok = false;
					while (!move_players.empty()) {
						stk[pr][pc].push(move_players.top());
						move_players.pop();
					}
					break;
				}
			}
		}
		if (!ok) continue;

		int dir = move_players.top().second;
		if (dir == 1) {
			//오른쪽
			if (pc + 1 == n || map[pr][pc + 1] == B) {
				//체스판 벗어나는 경우 or 파란색인 경우
				pair<int, int> move_player = move_players.top();
				move_players.pop();
				move_player.second = inverse_dir[dir];
				move_players.push(move_player);
				if (pc - 1 < 0 || map[pr][pc - 1] == B) {
					//이동 x
					while (!move_players.empty()) {
						stk[pr][pc].push(move_players.top());
						move_players.pop();
					}
				}
				else if (map[pr][pc - 1] == W){
					while (!move_players.empty()) {
						stk[pr][pc - 1].push(move_players.top());
						player[move_players.top().first] = { pr,pc - 1 };
						move_players.pop();
					}
				}
				else if (map[pr][pc - 1] == R) {
					stack<pair<int, int>> tmp;
					while (!move_players.empty()) {
						tmp.push(move_players.top());
						move_players.pop();
					}
					while (!tmp.empty()) {
						stk[pr][pc - 1].push(tmp.top());
						player[tmp.top().first] = { pr,pc - 1 };
						tmp.pop();
					}
				}
				
			}
			else if (map[pr][pc + 1] == W) {
				while (!move_players.empty()) {
					stk[pr][pc + 1].push(move_players.top());
					player[move_players.top().first] = { pr,pc + 1 };
					move_players.pop();
				}
			}
			else if (map[pr][pc + 1] == R) {
				stack<pair<int, int>> tmp;
				while (!move_players.empty()) {
					tmp.push(move_players.top());
					move_players.pop();
				}
				while (!tmp.empty()) {
					stk[pr][pc + 1].push(tmp.top());
					player[tmp.top().first] = { pr,pc + 1 };
					tmp.pop();
				}

			}

		}
		else if (dir == 2) {
			//왼쪽
			if (pc - 1 < 0 || map[pr][pc - 1] == B) {
				//체스판 벗어나는 경우 or 파란색인 경우
				pair<int, int> move_player = move_players.top();
				move_players.pop();
				move_player.second = inverse_dir[dir];
				move_players.push(move_player);
				if (pc + 1 == n || map[pr][pc + 1] == B) {
					//이동 x
					while (!move_players.empty()) {
						stk[pr][pc].push(move_players.top());
						move_players.pop();
					}
				}
				else if (map[pr][pc + 1] == W) {
					while (!move_players.empty()) {
						stk[pr][pc + 1].push(move_players.top());
						player[move_players.top().first] = { pr,pc + 1 };
						move_players.pop();
					}
				}
				else if (map[pr][pc + 1] == R) {
					stack<pair<int, int>> tmp;
					while (!move_players.empty()) {
						tmp.push(move_players.top());
						move_players.pop();
					}
					while (!tmp.empty()) {
						stk[pr][pc + 1].push(tmp.top());
						player[tmp.top().first] = { pr,pc + 1 };
						tmp.pop();
					}
				}
			}
			else if (map[pr][pc - 1] == W) {
				while (!move_players.empty()) {
					stk[pr][pc - 1].push(move_players.top());
					player[move_players.top().first] = { pr,pc - 1 };
					move_players.pop();
				}
			}
			else if (map[pr][pc - 1] == R) {
				stack<pair<int, int>> tmp;
				while (!move_players.empty()) {
					tmp.push(move_players.top());
					move_players.pop();
				}
				while (!tmp.empty()) {
					stk[pr][pc - 1].push(tmp.top());
					player[tmp.top().first] = { pr,pc - 1 };
					tmp.pop();
				}
			}
		}
		else if (dir == 3) {
			//상
			if (pr - 1 < 0 || map[pr - 1][pc] == B) {
				//체스판 벗어나는 경우 or 파란색인 경우
				pair<int, int> move_player = move_players.top();
				move_players.pop();
				move_player.second = inverse_dir[dir];
				move_players.push(move_player);
				if ( pr + 1 == n || map[pr + 1][pc] == B) {
					//이동 x
					while (!move_players.empty()) {
						stk[pr][pc].push(move_players.top());
						move_players.pop();
					}
				}
				else if (map[pr + 1][pc] == W) {
					while (!move_players.empty()) {
						stk[pr + 1][pc].push(move_players.top());
						player[move_players.top().first] = { pr + 1, pc};
						move_players.pop();
					}
				}
				else if (map[pr + 1][pc] == R) {
					stack<pair<int, int>> tmp;
					while (!move_players.empty()) {
						tmp.push(move_players.top());
						move_players.pop();
					}
					while (!tmp.empty()) {
						stk[pr + 1][pc].push(tmp.top());
						player[tmp.top().first] = { pr + 1, pc };
						tmp.pop();
					}
				}
			}
			else if (map[pr - 1][pc] == W) {
				while (!move_players.empty()) {
					stk[pr - 1][pc].push(move_players.top());
					player[move_players.top().first] = { pr - 1,pc};
					move_players.pop();
				}
			}
			else if (map[pr - 1][pc] == R) {
				stack<pair<int, int>> tmp;
				while (!move_players.empty()) {
					tmp.push(move_players.top());
					move_players.pop();
				}
				while (!tmp.empty()) {
					stk[pr - 1][pc].push(tmp.top());
					player[tmp.top().first] = { pr - 1, pc};
					tmp.pop();
				}
			}
		}
		else {
			//하
			if (pr + 1 == n || map[pr + 1][pc] == B) {
				//체스판 벗어나는 경우 or 파란색인 경우
				pair<int, int> move_player = move_players.top();
				move_players.pop();
				move_player.second = inverse_dir[dir];
				move_players.push(move_player);
				if (pr - 1 < 0 || map[pr - 1][pc] == B) {
					//이동 x
					while (!move_players.empty()) {
						stk[pr][pc].push(move_players.top());
						move_players.pop();
					}
				}
				else if (map[pr - 1][pc] == W) {
					while (!move_players.empty()) {
						stk[pr - 1][pc].push(move_players.top());
						player[move_players.top().first] = { pr - 1, pc};
						move_players.pop();
					}
				}
				else if (map[pr - 1][pc] == R) {
					stack<pair<int, int>> tmp;
					while (!move_players.empty()) {
						tmp.push(move_players.top());
						move_players.pop();
					}
					while (!tmp.empty()) {
						stk[pr - 1][pc].push(tmp.top());
						player[tmp.top().first] = { pr - 1, pc};
						tmp.pop();
					}
				}
			}
			else if (map[pr + 1][pc] == W) {
				while (!move_players.empty()) {
					stk[pr + 1][pc].push(move_players.top());
					player[move_players.top().first] = { pr + 1, pc};
					move_players.pop();
				}
			}
			else if (map[pr + 1][pc] == R) {
				stack<pair<int, int>> tmp;
				while (!move_players.empty()) {
					tmp.push(move_players.top());
					move_players.pop();
				}
				while (!tmp.empty()) {
					stk[pr + 1][pc].push(tmp.top());
					player[tmp.top().first] = { pr + 1, pc};
					tmp.pop();
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < k; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		player[i] = { r - 1,c - 1 };
		stk[r - 1][c - 1].push({ i,dir });
	}

	for (int turn = 1; ; turn++) {
		move();
		if (check()) {
			cout << turn << "\n";
			break;
		}
		if (turn >= 1000) {
			cout << -1 << "\n";
			break;
		}
	}

	return 0;
}