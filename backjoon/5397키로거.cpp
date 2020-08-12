#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

class node {
public:
	bool head;
	char c;
	node *nxt;
	node *prev;

	node() {
		head = false;
		nxt = NULL;
		prev = NULL;
	}

	node(char cc) : c(cc) {
		head = false;
		nxt = NULL;
		prev = NULL;
	}
};

class LinkedList {
public:
	node *head;

	LinkedList() { 
		head = new node();
		head->head = true;
	}

	~LinkedList() {
		node *n = head;
		node *dummy;

		while (1) {
			if (n->nxt != NULL) {
				dummy = n;
				n = n->nxt;
				delete(dummy);
			}
			else {
				delete(n);
				break;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		LinkedList *list = new LinkedList();
	
		string s;
		cin >> s;

		node *ptr = list->head;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '<') {
				if (ptr->prev != NULL)
					ptr = ptr->prev;
			}
			else if (s[i] == '>') {
				if (ptr->nxt != NULL)
					ptr = ptr->nxt;
			}
			else if (s[i] == '-') {
				if (ptr->head != true) {
					ptr->prev->nxt = ptr->nxt;

					if(ptr->nxt != NULL)
						ptr->nxt->prev = ptr->prev;
					ptr = ptr->prev;
				}				
			}
			else {
				node *n = new node(s[i]);
				
				n->nxt = ptr->nxt;
				n->prev = ptr;
				
				if (ptr->nxt != NULL) 
					ptr->nxt->prev = n;
				
				ptr->nxt = n;
				ptr = n;
			}
		}

		node *cur = list->head;
		while (1) {
			if (!cur->head) {
				cout << cur->c;
			}

			if (cur->nxt == NULL)
				break;
			else
				cur = cur->nxt;
		}
		cout << "\n";

		delete(list);
	}

	return 0;
}