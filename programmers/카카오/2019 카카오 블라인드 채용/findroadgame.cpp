#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<map>

using namespace std;


class node {
public:
	int r;
	int c;
	int num;

	node* left;
	node* right;

	node(int _r, int _c, int _num) : r(_r), c(_c), num(_num) {
		left = NULL;
		right = NULL;
	};
};

class tree {
public:
	node *root;
};

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
	if (p1.first.first > p2.first.first)
		return true;
	else if (p1.first.first == p2.first.first) {
		return p1.first.second < p2.first.second;
	}
	else {
		return false;
	}
}

tree *t;

vector<int> pre;
vector<int> post;

void preorder(node *n) {

	pre.push_back(n->num);

	if (n->left != NULL) {
		preorder(n->left);
	}
	if (n->right != NULL) {
		preorder(n->right);
	}
}

void postorder(node *n) {

	if (n->left != NULL) {
		postorder(n->left);
	}
	if (n->right != NULL) {
		postorder(n->right);
	}
	post.push_back(n->num);
}

void add(node* parent, node* child) {

	if (child->c < parent->c) {
		if (parent->left != NULL) {
			add(parent->left, child);
		}
		else {
			parent->left = child;
		}
	}
	else {
		if (parent->right != NULL) {
			add(parent->right, child);
		}
		else {
			parent->right = child;
		}
	}
	
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<pair<pair<int,int>, int>> v;

	for (int i = 0; i < nodeinfo.size(); i++) {
		v.push_back({ {nodeinfo[i][1], nodeinfo[i][0]},i + 1 });
	}

	sort(v.begin(), v.end(), cmp);

	t = new tree();

	t->root = new node(v[0].first.first, v[0].first.second, v[0].second);

	for (int i = 1; i < v.size(); i++) {
		int num = v[i].second;
		int r = v[i].first.first;
		int c = v[i].first.second;

		add(t->root, new node(r, c, num));
	}

	preorder(t->root);
	postorder(t->root);
	answer.push_back(pre);
	answer.push_back(post);

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> param = { {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	vector<vector<int>> ret = solution(param);

	return 0;
}
