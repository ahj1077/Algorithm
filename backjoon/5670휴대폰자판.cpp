#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class trie {
public:
	bool isterminal;
	trie *childs[26];

	trie(bool b) : isterminal(b) {
		for (int i = 0; i < 26; i++) {
			childs[i] = NULL;
		}
	}

	~trie() {
		for (int i = 0; i < 26; i++) {
			delete childs[i];
		}
	}
};

void insert(string s, trie* tree) {
	trie *cur = tree;

	for (int idx = 0; idx < s.size(); idx++) {
		char insertchar = s[idx];

		if (cur->childs[insertchar - 'a'] == NULL) {
			bool terminal = false;
			if (idx == s.size() - 1)
				terminal = true;
			cur->childs[insertchar - 'a'] = new trie(terminal);
			cur = cur->childs[insertchar - 'a'];
		}
		else {
			if (idx == s.size() - 1)
				cur->childs[insertchar - 'a']->isterminal = true;
			cur = cur->childs[insertchar - 'a'];
		}
	}
}

int find(string s, trie *tree, int cnt) {
	trie *cur = tree;

	for (int loop = 0; loop < s.size(); loop++) {
		
		char findchar = s[loop];

		int nxt = 0;

		for (int i = 0; i < 26; i++) {
			if (cur->childs[i] != NULL) {
				nxt++;
			}
		}


		if (loop == 0 || nxt != 1) {
			cnt++;
			cur = cur->childs[findchar - 'a'];
		}
		else {
			if (cur->isterminal)
				cnt++;
			cur = cur->childs[findchar - 'a'];
		}
	}

	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;

	while (cin >> n) {
		trie *tree = new trie(false);

		vector<string> v;
		
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
			insert(s, tree);
		}

		double total = 0;
		for (int i = 0; i < v.size(); i++) {
			total += find(v[i], tree, 0);
		}
		cout << fixed << setprecision(2) << total / n << "\n";
		delete tree;
	}

	return 0;
}