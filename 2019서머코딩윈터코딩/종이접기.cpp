#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<int> v;
	answer.push_back(0);


	for (int i = 2; i <= n; i++) {
		v.clear();

		for (int j = answer.size()-1; j >= 0; j--) {
			if (answer[j] == 0) 
				v.push_back(1);
			else
				v.push_back(0);
		}

		answer.push_back(0);
		for (int j = 0; j < v.size(); j++)
			answer.push_back(v[j]);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> v = solution(3);
	return 0;
}