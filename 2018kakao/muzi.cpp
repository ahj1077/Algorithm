#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	for (int i = 1; i <= food_times.size(); i++) 
		v.push_back(pair<int,int>(food_times.at(i - 1), i));
	
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int prevsz = 0;
		if (i > 0) 
			prevsz = v.at(i - 1).first;
		int cur_sz = v.at(i).first - prevsz;
		long long tmp = (long long)(cur_sz * (v.size() - i));

		if (tmp <= k) {
			k -= tmp;
		}
		else {
			k %= (v.size() - i);
			sort(v.begin(), v.end(), cmp);
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v.at(i).first >= cur_sz + prevsz) {
					cnt++;
					if (cnt == k + 1) {
						answer = v.at(i).second;
						break;
					}
				}
			}
			break;
		}
	}

	if (answer == 0) answer = -1;
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);

	int ans = solution(v, 5);
	
	return 0;
}