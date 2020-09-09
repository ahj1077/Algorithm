#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

int cache_size;

class Node {
public:
	string name;
	Node* prev = NULL;
	Node* next = NULL;

	Node(string _name) {
		name = _name;
	}
};

class Cache {
public:
	Node *head;
	Node* tail;
	int size;
	map<string, Node*> mymap;

	Cache() {
		size = 0;
		head = new Node("");
		tail = new Node("");
		head->next = tail;
		tail->prev = head;
	};

	void push_back(Node  *n) {
		tail->prev->next = n;
		n->prev = tail->prev;
		n->next = tail;
		tail->prev = n;
		mymap.insert({ n->name, n });
		size++;
	}

	bool find(string name) {

		map<string, Node*>::iterator iter = mymap.find(name);
		if (iter == mymap.end()) {
			if (size == cache_size) {
				Node* n = head->next;
				head->next = head->next->next;
				head->next->prev = head;

				mymap.erase(n->name);
				delete(n);
				size--;
			}

			Node* n = new Node(name);
			push_back(n);
			return false;
		}
		else{
			Node* n = iter->second;
			n->prev->next = n->next;
			n->next->prev = n->prev;

			mymap.erase(n->name);
			delete(n);
			size--;

			Node* new_n = new Node(name);
			push_back(new_n);
			return true;
		}
	}


};

Cache *cache = new Cache();

string toLower(string str) {

	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		ret += tolower(str[i]);
	}
	return ret;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	cache_size = cacheSize;
	if (cacheSize == 0) return 5 * cities.size();

	for (int i = 0; i < cities.size(); i++) {
		string city = toLower(cities[i]);
		
		if (cache->find(city)) {
			answer++;
		}
		else {
			answer += 5;
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> param = { "Jeju", "Pangyo","NewYork", "newyork"};

	int ret = solution(2, param);
	cout << ret;

	return 0;

}
