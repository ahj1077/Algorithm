#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;

class trie {
public:
	bool isterminal;
	trie *subtree[10];

	trie() {
		isterminal = false;
		for (int i = 0; i < 10; i++)
			subtree[i] = NULL;
	}
	trie(bool b) {
		isterminal = b;
		for (int i = 0; i < 10; i++)
			subtree[i] = NULL;
	}
};

void insert(string s, trie *tre) {
	trie *cur = tre;

	for (int loop = 0; loop < s.size(); loop++) {
		char insertchar = s[loop];

		if (cur->subtree[insertchar - '0'] == NULL) {
			bool t = false;
			if (loop == s.size() - 1)
				t = true;
			cur->subtree[insertchar - '0'] = new trie(t);
			cur = cur->subtree[insertchar - '0'];
		}
		else {
			if (loop == s.size() - 1)
				cur->subtree[insertchar - '0']->isterminal = true;
			cur = cur->subtree[insertchar - '0'];
		}
	}
}

bool find(string s, trie *tre) {
	trie *cur = tre;

	for (int loop = 0; loop < s.size(); loop++) {
		if (cur->isterminal) {
			if (s.size() > loop) return false;
			else if (s.size() == loop) {
				for (int i = 0; i < 10; i++) {
					if (cur->subtree[i] != NULL)
						return false;
				}
				return true;
			}
		}

		char findchar = s[loop];

		if (cur->subtree[findchar - '0'] != NULL) {
			cur = cur->subtree[findchar - '0'];
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		
		trie *tree = new trie();
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
			insert(s, tree);
		}
		
		string str = "YES";
		for (int i = 0; i < v.size(); i++) {
			if (!find(v[i], tree)) {
				str = "NO";
				break;
			}
		}
		cout << str << "\n";

		delete tree;
	}


	return 0;
}