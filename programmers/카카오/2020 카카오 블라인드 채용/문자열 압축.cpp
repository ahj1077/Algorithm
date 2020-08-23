#include<iostream>
#include <string>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;


string tostring(int num) {
	string ret = "";
	bool lsb = false;
	for (int i = 1000; i >= 1; i /= 10) {
		int n = num / i;
		if (n != 0 && !lsb ) {
			lsb = true;
			ret += (char)(n + '0');
		}
		else if (lsb) {
			ret += (char)(n + '0');
		}
	}
	return ret;
}

int zip(int num, const string s) {
	int ret = s.size();
	string tmp = s;

	for (int i = 0; i <= tmp.size() - num; i += num) {
		string pattern = "";

		pattern = tmp.substr(i, num);
		
		int cnt = 1;

		for (int j = i + num; j < tmp.size();) {
			if (tmp.substr(j, num) == pattern) {
				cnt++;
				j = j + num;
				if (j == tmp.size() && cnt > 1) {
					string new_str = "";
					new_str.append(tmp.substr(0, i));
					new_str.append(tostring(cnt));
					new_str.append(pattern);
					new_str.append(tmp.substr(j, tmp.size() - j));
					tmp = new_str;
					i+=tostring(cnt).size();
					break;
				}
			}
			else {
				if (cnt > 1) {
					string new_str = "";
					new_str.append(tmp.substr(0, i));
					new_str.append(tostring(cnt));
					new_str.append(pattern);
					new_str.append(tmp.substr(j, tmp.size() - j));
					tmp = new_str;
					i+=tostring(cnt).size();
				}
				break;
			}
		}
		int len = tmp.size();
		ret = min(ret, len);
	}

	return ret;
}

int solution(string s) {
	int answer = 0;
	answer = s.size();

	for (int i = 1; i <= (s.size()/2); i++) {
		int ret = zip(i, s);
		answer = min(ret, answer);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "abcabcabcabcdededededede";
	string s1 = "xababcdcdababcdcd";
	string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string s3 = "abcdabcdabc";

	int ret = solution(s);
	return 0;
}
