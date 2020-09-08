#include <iostream>
#include<algorithm>
#include <vector>
#include<queue>
#include<string>
#include<map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> mymap;

	for (int i = 0; i < record.size(); i++) {
		string s[3];
		int cnt = 0;
		int start = 0;
		for (int j = 0; j < record.at(i).size(); j++) {
			if (j == record.at(i).size() - 1) {
				s[cnt++] = record.at(i).substr(start, j - start + 1);
				break;
			}
			if (record.at(i).at(j) == ' ') {
				s[cnt++] = record.at(i).substr(start, j - start);
				start = j + 1;
			}
		}

		if (s[0]== "Enter") {
			map<string, string>::iterator iter;
			iter = mymap.find(s[1]);
			if (iter != mymap.end()) {
				iter->second = s[2];
			}
			else {
				mymap.insert(pair<string, string>(s[1], s[2]));
			}
		}
		else if (s[0] == "Change") {
			map<string, string>::iterator iter;
			iter = mymap.find(s[1]);
			if (iter != mymap.end()) {
				iter->second = s[2];
			}
		}
	}

	for (int i = 0; i < record.size(); i++) {
		string s[3];
		int cnt = 0;
		int start = 0;
		for (int j = 0; j < record.at(i).size(); j++) {
			if (j == record.at(i).size() - 1) {
				s[cnt++] = record.at(i).substr(start, j - start + 1);
				break;
			}
			if (record.at(i).at(j) == ' ') {
				s[cnt++] = record.at(i).substr(start, j - start);
				start = j + 1;
			}
		}

		if (s[0] == "Enter") {
			map<string, string>::iterator iter;
			iter = mymap.find(s[1]);
			if (iter != mymap.end()) {
				string tmp = "";
				tmp.append(iter->second);
				tmp.append("님이 들어왔습니다.");
				answer.push_back(tmp);
			}
		}
		else if (s[0] == "Leave") {
			map<string, string>::iterator iter;
			iter = mymap.find(s[1]);
			if (iter != mymap.end()) {
				string tmp = "";
				tmp.append(iter->second);
				tmp.append("님이 나갔습니다.");
				answer.push_back(tmp);
			}
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s1 = "Enter uid1234 Muzi";
	string s2 = "Enter uid4567 Prodo";
	string s3 = "Leave uid1234";
	string s4 = "Enter uid1234 Prodo";
	string s5 = "Change uid4567 Ryan";
	vector<string> r;
	r.push_back(s1);
	r.push_back(s2);
	r.push_back(s3);
	r.push_back(s4);
	r.push_back(s5);

	vector<string> a = solution(r);
	return 0;
}