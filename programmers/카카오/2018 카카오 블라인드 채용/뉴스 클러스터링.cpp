#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

map<string, int> mymap;
vector<string> A, B;
int AnB, AuB;

void make(string str, bool f) {

	for (int i = 0; i < str.size()-  1; i++) {
		string token = str.substr(i, 2);

		if (token[0] >= 'A' && token[0] <= 'Z') {
			token[0] = token[0] - 'A' + 'a';
		}
		if (token[1] >= 'A' && token[1] <= 'Z') {
			token[1] = token[1] - 'A' + 'a';
		}

		if (token[0] < 'a' || token[0] > 'z') continue;
		if (token[1] < 'a' || token[1] > 'z') continue;

		if (f) A.push_back(token);
		else B.push_back(token);
	}
}
int solution(string str1, string str2) {
	int answer = 0;

	make(str1,true);
	make(str2,false);

	for (int i = 0; i < A.size(); i++) {
		map<string, int>::iterator iter;
		iter = mymap.find(A[i]);
		if (iter == mymap.end()) {
			mymap.insert({ A[i],1 });
		}
		else {
			mymap[A[i]]++;
		}
		AuB++;
	}

	for (int i = 0; i < B.size(); i++) {
		map<string, int>::iterator iter;
		iter = mymap.find(B[i]);
		if (iter != mymap.end()) {
			if (mymap[B[i]] > 0) {
				mymap[B[i]]--;
				AnB++;
			}
			else {
				AuB++;
			}
		}
		else {
			AuB++;
		}
	}
	if (AuB == 0) answer = 65536;
	else
		answer = ((double)AnB / AuB) * 65536;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ret = solution("aa1+aa2", "AAAA12");
	cout << ret;

	return 0;

}
