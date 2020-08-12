#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

int n;
bool visit[10001][10001];
bool map[100][100];
int mapnum[100][100];

int dirr[4] = { -1,1,0,0 };
int dirc[4] = { 0,0,-1,1 };

class drone {
public:
	pair<int, int> pos1;
	pair<int, int> pos2;
	int depth;

	drone(int x1, int y1, int x2, int y2, int d) : pos1({ x1,y1 }), pos2({x2, y2}), depth(d) {}
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board[0].size();

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mapnum[i][j] = (cnt++);
			map[i][j] = board[i][j];
		}
	}


	queue<drone> q;
	q.push(drone(0, 0, 0, 1, 0));
	visit[1][2] = true;
	visit[2][1] = true;

	while (!q.empty()) {
		pair<int,int> pos1 = q.front().pos1;
		pair<int,int> pos2 = q.front().pos2;
		int depth = q.front().depth;
		q.pop();

		if ((pos1.first == n - 1 && pos1.second == n - 1) || (pos2.first == n - 1 && pos2.second == n - 1)) {
			answer = depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nxtpos1r = pos1.first + dirr[i];
			int nxtpos1c = pos1.second + dirc[i];

			int nxtpos2r = pos2.first + dirr[i];
			int nxtpos2c = pos2.second + dirc[i];

			if (nxtpos1r < 0 || nxtpos2r < 0 || nxtpos1r >= n || nxtpos2r >= n) continue;
			if (nxtpos1c < 0 || nxtpos2c < 0 || nxtpos1c >= n || nxtpos2c >= n) continue;
			if (map[nxtpos1r][nxtpos1c] || map[nxtpos2r][nxtpos2c]) continue;
			
			if (!visit[mapnum[nxtpos1r][nxtpos1c]][mapnum[nxtpos2r][nxtpos2c]]) {
				visit[mapnum[nxtpos1r][nxtpos1c]][mapnum[nxtpos2r][nxtpos2c]] = true;
				visit[mapnum[nxtpos2r][nxtpos2c]][mapnum[nxtpos1r][nxtpos1c]] = true;
				q.push(drone(nxtpos1r,nxtpos1c,nxtpos2r,nxtpos2c,depth+1));
			}
		}

		//가로라면
		if (pos1.first == pos2.first) {
			if (pos1.first - 1 >= 0 && !map[pos1.first - 1][pos1.second] && !map[pos2.first - 1][pos2.second]){
				if (!visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first - 1][pos1.second]]) {
					visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first - 1][pos1.second]] = true;
					visit[mapnum[pos1.first - 1][pos1.second]][mapnum[pos1.first][pos1.second]] = true;
					q.push(drone(pos1.first, pos1.second, pos1.first - 1, pos1.second, depth + 1));
				}
				if (!visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first - 1][pos2.second]]) {
					visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first - 1][pos2.second]] = true;
					visit[mapnum[pos2.first - 1][pos2.second]][mapnum[pos2.first][pos2.second]] = true;
					q.push(drone(pos2.first, pos2.second, pos2.first - 1, pos2.second, depth + 1));
				}	
			}
			if (pos1.first + 1 < n && !map[pos1.first + 1][pos1.second] && !map[pos2.first + 1][pos2.second]) {
				if (!visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first + 1][pos1.second]]) {
					visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first + 1][pos1.second]] = true;
					visit[mapnum[pos1.first + 1][pos1.second]][mapnum[pos1.first][pos1.second]] = true;
					q.push(drone(pos1.first, pos1.second, pos1.first + 1, pos1.second, depth + 1));
				}
				if (!visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first + 1][pos2.second]]) {
					visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first + 1][pos2.second]] = true;
					visit[mapnum[pos2.first + 1][pos2.second]][mapnum[pos2.first][pos2.second]] = true;
					q.push(drone(pos2.first, pos2.second, pos2.first + 1, pos2.second, depth + 1));
				}
			}
		}
		//세로라면
		else {
			if (pos1.second - 1 >= 0 && !map[pos1.first][pos1.second - 1] && !map[pos2.first][pos2.second - 1]) {
				if (!visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first][pos1.second - 1]]) {
					visit[mapnum[pos1.first][pos1.second - 1]][mapnum[pos1.first][pos1.second]] = true;
					visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first][pos1.second - 1]] = true;
					q.push(drone(pos1.first, pos1.second, pos1.first, pos1.second - 1, depth + 1));
				}
				if (!visit[mapnum[pos2.first][pos2.second - 1]][mapnum[pos2.first][pos2.second]]) {
					visit[mapnum[pos2.first][pos2.second - 1]][mapnum[pos2.first][pos2.second]] = true;
					visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first][pos2.second - 1]] = true;
					q.push(drone(pos2.first, pos2.second, pos2.first, pos2.second - 1, depth + 1));
				}
			}
			if (pos1.second + 1 < n && !map[pos1.first][pos1.second + 1] && !map[pos2.first][pos2.second + 1]) {
				if (!visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first][pos1.second + 1]]) {
					visit[mapnum[pos1.first][pos1.second + 1]][mapnum[pos1.first][pos1.second]] = true;
					visit[mapnum[pos1.first][pos1.second]][mapnum[pos1.first][pos1.second + 1]] = true;
					q.push(drone(pos1.first, pos1.second, pos1.first, pos1.second + 1, depth + 1));
				}
				if (!visit[mapnum[pos2.first][pos2.second + 1]][mapnum[pos2.first][pos2.second + 1]]) {
					visit[mapnum[pos2.first][pos2.second + 1]][mapnum[pos2.first][pos2.second]] = true;
					visit[mapnum[pos2.first][pos2.second]][mapnum[pos2.first][pos2.second + 1]] = true;
					q.push(drone(pos2.first, pos2.second, pos2.first, pos2.second + 1, depth + 1));
				}
			}
		}
		
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	return 0;
}