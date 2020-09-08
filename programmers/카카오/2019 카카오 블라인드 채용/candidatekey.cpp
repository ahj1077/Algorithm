#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;

bool key[20];
vector<int> keyidx;
int ans = 0;
map<int, bool> candidate;

bool check(int keybit) {
	map<int, bool>::iterator iter;
	for (iter = candidate.begin(); iter != candidate.end(); iter++) {
		int cmp = iter->first & keybit;
		if (cmp == iter->first) {
			return false;
		}
	}
	return true;
}
void dfs(int start,int depth,int d, int col, int keybit, vector<vector<string>> relation) {
	if (depth == d) {
		if (check(keybit)) {
			map<string, bool> mymap;

			for (int j = 0; j < relation.size(); j++) {
				string key = "";

				for (int i = 0; i < keyidx.size(); i++) {
					/*string s = "A" + keyidx.at(i);
					key.append(s);*/
					key.append(relation[j].at(keyidx.at(i)));
				}

				map<string, bool>::iterator iter;
				iter = mymap.find(key);
				if (iter != mymap.end()) {
					return;
				}
				else {
					mymap.insert(pair<string, bool>(key, true));
				}
			}
			candidate.insert(pair<int, bool>(keybit, true));
			ans++;
		}
		return;
	}
	
	for (int i = start; i < col; i++) {
		if (key[i] == false) {
			key[i] = true;
			keyidx.push_back(i);
			int k = 0;
			k = keybit | (1 << i);
			dfs(i + 1, depth, d + 1, col, k , relation);
			keyidx.pop_back();
			key[i] = false;
		}
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	int keycol = 0;
	map<string, bool> mymap;
	vector<string> row[20];
	for (int i = 0; i < relation.size(); i++) {
		row[i] = relation[i];
	}

	for (int i = 0; i < row[0].size(); i++) {
		bool ok = true;

		for (int j = 0; j < relation.size(); j++) {
			map<string, bool>::iterator iter;
			iter = mymap.find(row[j].at(i));
			
			if (iter != mymap.end()) {
				ok = false;
				mymap.clear();
				break;
			}
			else {
				mymap.insert(pair<string, bool>(row[j].at(i), true));
			}
		}

		if (ok == true) {
			key[i] = true;
			int k = 0;
			k = (1 << i);
			candidate.insert(pair<int, bool>(k, true));
			keycol++;
			mymap.clear();
		}
	}

	answer = keycol;
	
	for (int i = 2; i <= row[0].size() - keycol; i++) {
		dfs(0, i, 0 , row[0].size(), 0, relation);
	}

	answer += ans;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> v[6];
	v[0].push_back("100");
	v[0].push_back("ryan");
	v[0].push_back("music");
	v[0].push_back("2");

	v[1].push_back("200");
	v[1].push_back("apeach");
	v[1].push_back("math");
	v[1].push_back("2");

	v[2].push_back("300");
	v[2].push_back("tube");
	v[2].push_back("computer");
	v[2].push_back("3");

	v[3].push_back("400");
	v[3].push_back("con");
	v[3].push_back("computer");
	v[3].push_back("1");

	v[4].push_back("500");
	v[4].push_back("muzi");
	v[4].push_back("music");
	v[4].push_back("3");

	v[5].push_back("600");
	v[5].push_back("apeach");
	v[5].push_back("music");
	v[5].push_back("2");
	vector<vector<string>> vv;
	vv.push_back(v[0]);
	vv.push_back(v[1]);
	vv.push_back(v[2]);
	vv.push_back(v[3]);
	vv.push_back(v[4]);
	vv.push_back(v[5]);

	
	int a = solution(vv);

	return 0;
}