#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, r;
long long k;
long long facto[21];
string nums[21] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
bool number[21];

vector<string> answer;

void init() {
	facto[0] = 1;
	for (int i = 1; i <= 20; i++) {
		facto[i] = facto[i - 1] * i;
	}
}

void p1() {
	
	long long rank = 0;
	int cpy_n = n - 1;

	while (1) {
		long long idx = (k - 1 - rank) / facto[cpy_n];
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!number[i]) {
				if (cnt == idx) {
					answer.push_back(nums[i]);
					number[i] = true;
					break;
				}
				cnt++;
			}
		}

		rank += (idx * facto[cpy_n]);
		cpy_n--;
		if (rank == k - 1)
			break;
	}

	for (int i = 1; i <= n; i++) {
		if (!number[i]) {
			answer.push_back(nums[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	cin >> n;

	int pnum;
	cin >> pnum;

	if (pnum == 1) {
		cin >> k;

		p1();
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << " ";
		cout << "\n";

	}
	else {
		long long rank = 0;
		int cpy_n = n - 1;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			
			int cnt = 0;
			for (int i = 1; i < num; i++) {
				if (!number[i]) {
					cnt++;
				}
			}

			number[num] = true;
			rank += (cnt * facto[cpy_n]);
			cpy_n--;
		}

		rank++;
		cout << rank << "\n";
	}
	
	return 0;
}