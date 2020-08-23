#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

set<string> myset;
map<string, int> mymap;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	answer = { 1, (int) gems.size()};

	for (int i = 0; i < gems.size(); i++) {
		myset.insert(gems[i]);
	}

	int left = 0;
	int right = myset.size() - 1;
	
	for (int i = 0; i <= right; i++) {
		if (mymap.find(gems[i]) != mymap.end()) {
			mymap[gems[i]]++;
		}
		else {
			mymap.insert({ gems[i], 1 });
		}
	}

	while (right < gems.size()) {
		if (mymap.size() == myset.size()) {
			if (answer[1] - answer[0] > right - left) {
				answer = { left + 1,right + 1};
			}
		}

		if (mymap.size() < myset.size()) {
			if (right == gems.size() - 1) {
				break;
			}

			if (mymap.find(gems[right + 1]) == mymap.end()) {
				mymap.insert({ gems[right + 1], 1 });
			}
			else {
				mymap[gems[right + 1]]++;
			}
			right++;
		}
		else if(mymap.size() == myset.size()){
			if (left == right) {
				if (right == gems.size() - 1) {
					break;
				}

				if (mymap.find(gems[right + 1]) == mymap.end()) {
					mymap.insert({ gems[right + 1], 1 });
				}
				else {
					mymap[gems[right + 1]]++;
				}
				right++;
			}
			else {
				mymap[gems[left]]--;
				if (mymap[gems[left]] == 0) {
					mymap.erase(mymap.find(gems[left]));
				}
				left++;
			}
		}
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> ret = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });

	cout << ret[0] << " " << ret[1] << "\n";
	return 0;
}