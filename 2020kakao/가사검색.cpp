#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class node {
public:
	node *childs[26];
	char s;
	bool isleaf;
	int cnt;

	node() {
		isleaf = false;
		cnt = 0;
		memset(childs, NULL, sizeof(childs));
	}
	node(char ss, int c, bool _isleaf) : s(ss), cnt(c), isleaf(_isleaf){
		memset(childs, NULL, sizeof(childs));
	}
};


class tree {
public:
	node *root;

	tree() {
		root = new node();
	}

	void insert(string s) {
		node *cur = root;
		char insert_c = s[0];
		int str_sz = s.size();
		root->cnt++;

		for (int loop = 0; loop < str_sz; loop++) {
			bool find = false;
			insert_c = s[loop];

			for (int i = 0; i < 26; i++) {
				if (cur->childs[i] == NULL) continue;
				
				if (cur->childs[i]->s == insert_c) {
					find = true;
					cur->childs[i]->cnt++;
					cur = cur->childs[i];
				}
			}

			if (!find) {
				if (loop == str_sz - 1) {
					cur->childs[insert_c - 'a'] = new node(insert_c, 1,true);
				}
				else {
					cur->childs[insert_c - 'a'] = new node(insert_c, 1,false);
					cur = cur->childs[insert_c - 'a'];
				}
			}
		}
	}

	int find(string query) {
		int q_size = query.size();

		queue<pair<node*,int>> q;
		q.push({ root, 0 });
		int cnt = 0;

		while (!q.empty()) {
			int depth = q.front().second;
			node *n = q.front().first;
			q.pop();

			if (n->isleaf) {
				cnt++;
				break;
			}

			char findchar = query[depth];


			if (findchar != '?') {
				for (int i = 0; i < 26; i++) {
					if (n->childs[i] == NULL) continue;
					if (n->childs[i]->s == findchar) {
						if (query[depth + 1] == '?')
							return n->childs[i]->cnt;

						q.push({n->childs[i], depth + 1});
						break;
					}
				}
			}
			else {
				//?ÀÏ °æ¿ì
				cnt = root->cnt;
				break;
			}
		}
	
		return cnt;
	}
};

tree t[10001];
tree rt[10001];

string reverse(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		char tmp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = tmp;
	}
	return s;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> reverseword;

	for (int i = 0; i < words.size(); i++) {
		reverseword.push_back(reverse(words[i]));
	}

	for (int i = 0; i < words.size(); i++) {
		t[words[i].size()].insert(words[i]);
	}
	for (int i = 0; i < reverseword.size(); i++) {
		rt[reverseword[i].size()].insert(reverseword[i]);
	}


	for (int i = 0; i < queries.size(); i++) {
		int cnt = 0;
		if (queries[i][0] == '?') {
			cnt = rt[queries[i].size()].find(reverse(queries[i]));
		}
		else {
			cnt = t[queries[i].size()].find(queries[i]);
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> words, queries;
	words.push_back("fr");
	words.push_back("fro");
	words.push_back("froze");
	words.push_back("frozen");
	words.push_back("f");
	words.push_back("a");

	queries.push_back("f?");
	queries.push_back("fr?");
	queries.push_back("???rf");
	queries.push_back("?");
	queries.push_back("?");
	queries.push_back("?");

	solution(words, queries);


	return 0;
}