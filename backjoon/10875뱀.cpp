#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define GARO 0
#define SERO 1

using namespace std;

int l, n;
int nxtdir[4][2];

class line {
public:
	int up_x, up_y;
	int down_x, down_y;
	int left_x, left_y;
	int right_x, right_y;
	int dir;

	line(){}
	line(int ux,int uy, int dx,int dy,int ddir) : up_x(ux), up_y(uy), down_x(dx), down_y(dy), dir(ddir){}

	void setGARO(int lx,int ly, int rx, int ry, int ddir) {
		left_x = lx;
		left_y = ly;
		right_x = rx;
		right_y = ry;
		dir = ddir;
	}
};

vector<line> lines;

void setnxtdir() {
	nxtdir[UP][0] = LEFT;
	nxtdir[UP][1] = RIGHT;

	nxtdir[DOWN][0] = RIGHT;
	nxtdir[DOWN][1] = LEFT;

	nxtdir[LEFT][0] = DOWN;
	nxtdir[LEFT][1] = UP;

	nxtdir[RIGHT][0] = UP;
	nxtdir[RIGHT][1] = DOWN;
}

int check(int x,int y,int dir, int t) {
	int ret = 987654321;

	for (int i = 0; i < lines.size() - 1; i++) {
		int line_dir = lines[i].dir;

		if (line_dir == GARO) {
			if (dir == RIGHT) {
				if (y != lines[i].left_y) continue;
				if (x <= lines[i].left_x && x + t >= lines[i].left_x) {
					ret = min(ret, lines[i].left_x - x);
				}
			}
			else if (dir == LEFT){
				if (y != lines[i].left_y) continue;
				if (x >= lines[i].right_x && x - t <= lines[i].right_x) {
					ret = min(ret, x - lines[i].right_x);
				}
			}
			else if (dir == UP) {
				if (y <= lines[i].left_y) {
					if (x >= lines[i].left_x && x <= lines[i].right_x) {
						if (y + t >= lines[i].left_y) {
							ret = min(ret,lines[i].left_y - y);
						}
					}
				}
			}
			else {
				if (y >= lines[i].left_y) {
					if (x >= lines[i].left_x && x <= lines[i].right_x) {
						if (y - t <= lines[i].left_y) {
							ret = min(ret, y - lines[i].left_y);
						}
					}
				}
			}
		}
		else {
			if (dir == UP) {
				if (x != lines[i].up_x) continue;
				if (y <= lines[i].down_y && y + t >= lines[i].down_y) {
					ret = min(ret, lines[i].down_y - y);
				}
			}
			else if (dir == DOWN) {
				if (x != lines[i].up_x) continue;
				if (y >= lines[i].up_y && y - t <= lines[i].up_y) {
					ret = min(ret, y - lines[i].up_y);
				}
			}
			else if (dir == LEFT) {
				if (x >= lines[i].up_x) {
					if (y <= lines[i].up_y && y >= lines[i].down_y) {
						if (x - t <= lines[i].up_x) {
							ret = min(ret, x - lines[i].up_x);
						}
					}
				}
			}
			else {
				if (x <= lines[i].up_x) {
					if (y <= lines[i].up_y && y >= lines[i].down_y) {
						if (x + t >= lines[i].up_x) {
							ret = min(ret, lines[i].up_x - x);
						}
					}
				}
			}
		}
	}

	return ret;
}

void setline() {
	lines.push_back(line(-l - 1, l + 1, -l - 1, -l - 1, SERO));
	lines.push_back(line(l + 1, l + 1, l + 1, -l - 1, SERO));
	
	line ln1, ln2;
	
	ln1.setGARO(-l - 1, l + 1, l + 1, l + 1, GARO);
	ln2.setGARO(-l - 1, -l - 1, l + 1, -l - 1, GARO);
	lines.push_back(ln1);
	lines.push_back(ln2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l;
	cin >> n;
	
	setnxtdir();
	setline();
	int head_x = 0, head_y = 0;
	int direction = RIGHT;
	bool ok = false;

	long long time = 0;


	for (int i = 0; i < n; i++) {
		int t;
		char dir;
		cin >> t >> dir;

		int ret = check(head_x, head_y, direction, t);

		if (ret != 987654321) {
			ok = true;
			cout << time + ret << "\n";
			break;
		}
		else {
			if (direction == RIGHT) {
				line ln;
				ln.setGARO(head_x, head_y, head_x + t, head_y, GARO);
				lines.push_back(ln);
				head_x += t;
			}
			else if (direction == LEFT) {
				line ln;
				ln.setGARO(head_x - t, head_y, head_x, head_y, GARO);
				lines.push_back(ln);
				head_x -= t;
			}
			else if (direction == UP) {
				lines.push_back(line(head_x, head_y + t, head_x, head_y, SERO));
				head_y += t;
			}
			else {
				lines.push_back(line(head_x, head_y, head_x, head_y - t, SERO));
				head_y -= t;
			}

			time += t;

			int leftorright;
			if (dir == 'L') leftorright = 0;
			else leftorright = 1;

			direction = nxtdir[direction][leftorright];
		}
	}

	if (!ok) {
		int ret = check(head_x, head_y, direction, 280000000);
		cout << time + ret << "\n";
	}


	return 0;
}