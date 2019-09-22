#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>

using namespace std;

class node {
public:
	int num;
	int col;
	node *left;
	node *right;

	node(int c, int n) : col(c), num(n) {
		left = NULL;
		right = NULL;
	}
};

class tree {
public:
	node *root;
	tree() {
		root = NULL;
	}
};


tree t;
vector<node> v[100001];
vector<int> preorder_v;
vector<int> postorder_v;
int h = 0;

void preorder(node *n) {

	if (n->left != NULL) {
		preorder_v.push_back(n->left->num);
		preorder(n->left);
	}
	if (n->right != NULL) {
		preorder_v.push_back(n->right->num);
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
	postorder_v.push_back(n->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	for (int i = 0; i < nodeinfo.size(); i++) {
		if (nodeinfo.at(i).at(1) > h)
			h = nodeinfo.at(i).at(1);

		v[nodeinfo.at(i).at(1)].push_back(node(nodeinfo.at(i).at(0), i + 1));
	}

	node *n = new node(v[h].at(0).col, v[h].at(0).num);
	t.root = n;

	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < v[i].size(); j++) {

			node *cur = t.root;
			int nodenum = v[i].at(j).num;
			int nodecol = v[i].at(j).col;

			while (1) {
				if (nodecol < cur->col) {
					if (cur->left == NULL) {
						node *n = new node(nodecol, nodenum);
						cur->left = n;
						break;
					}
					cur = cur->left;
				}
				else {
					if (cur->right == NULL) {
						node *n = new node(nodecol, nodenum);
						cur->right = n;
						break;
					}
					cur = cur->right;
				}
			}
		}
	}

	preorder_v.push_back(t.root->num);
	preorder(t.root);
	postorder(t.root);

	answer.push_back(preorder_v);
	answer.push_back(postorder_v);

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<vector<int>> para;
	vector<int> p;
	p.push_back(5);
	p.push_back(3);
	para.push_back(p);
	p.clear();

	p.push_back(11);
	p.push_back(5);
	para.push_back(p);
	p.clear();

	p.push_back(13);
	p.push_back(3);
	para.push_back(p);
	p.clear();

	p.push_back(3);
	p.push_back(5);
	para.push_back(p);
	p.clear();

	p.push_back(6);
	p.push_back(1);
	para.push_back(p);
	p.clear();

	p.push_back(1);
	p.push_back(3);
	para.push_back(p);
	p.clear();

	p.push_back(8);
	p.push_back(6);
	para.push_back(p);
	p.clear();

	p.push_back(7);
	p.push_back(2);
	para.push_back(p);
	p.clear();

	p.push_back(2);
	p.push_back(2);
	para.push_back(p);
	p.clear();

	para = solution(para);


	return 0;
}