#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//0은 기둥 1은 보, 0은 왼쪽 (위쪽) 1은 오른쪽(아래)
bool map[2][101][101];


bool check(int n, int col_or_bo) {
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[0][i][j]) {
				if (i == 0) {
					continue;
				}
				if (j - 1 >= 0 && map[1][i][j - 1]) {
					continue;
				}
				if (map[1][i][j]){ 
					continue;
				}
				if (i - 1 >= 0 && map[0][i - 1][j]) {
					continue;
				}

				return false;
			}
			else if (map[1][i][j]) {
				if (i - 1 >= 0 && map[0][i - 1][j]) {
					continue;
				}
				if (i - 1 >= 0 && j + 1 <= n && map[0][i - 1][j + 1]) {
					continue;
				}
				if (j - 1 >= 0 && map[1][i][j - 1] && j + 1 <= n && map[1][i][j + 1]) {
					continue;
				}
				return false;
			}
		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
		
	for (int i = 0; i < build_frame.size(); i++) {
		int target_x = build_frame[i][0];
		int target_y = build_frame[i][1];
		int col_or_bo = build_frame[i][2];
		int add_or_del = build_frame[i][3];

		if (add_or_del == 0) {
			//삭제
			if (col_or_bo == 1) {
				map[col_or_bo][target_y][target_x] = false;
				if (!check(n,col_or_bo)) {
					map[col_or_bo][target_y][target_x] = true;
				}
			}
			else {
				map[col_or_bo][target_y][target_x] = false;
				if (!check(n, col_or_bo)) {
					map[col_or_bo][target_y][target_x] = true;
				}
			}
		}
		else {
			//삽입
			if (col_or_bo == 1) { //보
				map[col_or_bo][target_y][target_x] = true;
				if (!check(n, target_x, target_y, col_or_bo)) {
					map[col_or_bo][target_y][target_x] = false;
				}
			}
			else {
				map[col_or_bo][target_y][target_x] = true;
				if (!check(n, target_x, target_y, col_or_bo)) {
					map[col_or_bo][target_y][target_x] = false;
				}
			}
		}
	}

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (map[0][y][x]) {
				vector<int> v;
				v.push_back(x);
				v.push_back(y);
				v.push_back(0);
				answer.push_back(v);
			}

			if (map[1][y][x]) {
				vector<int> v;
				v.push_back(x);
				v.push_back(y);
				v.push_back(1);
				answer.push_back(v);
			}
		}
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> param;
	vector<vector<int>> param2;

	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(5);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(5);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(4);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	param.push_back(v);
	
	v.clear();
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	param.push_back(v);

	v.clear();
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	param2.push_back(v);
	
	v.clear();
	v.push_back(2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(4);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	param2.push_back(v);

	v.clear();
	v.push_back(2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	param2.push_back(v);

	v.clear();
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	param2.push_back(v);

	v.clear();
	v.push_back(2);
	v.push_back(2);
	v.push_back(0);
	v.push_back(1);
	param2.push_back(v);

	solution(5, param2);

	return 0;
}