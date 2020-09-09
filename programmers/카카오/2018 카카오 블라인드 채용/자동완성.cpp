#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
public:
    int cnt;
    char c;
    Node* arr[26];
    
    Node(char _c){
        cnt = 1;
        c = _c;
        for(int i=0; i<26; i++){
            arr[i] = NULL;
        }
    }
};

class trie{
public:
    Node *root;
    
    trie(){
        root = new Node(' ');
    }
    
    int find(string s){
        int ret = 0;
        int idx = 0;
        Node *now = root;
        
        while(1){
            if(idx == s.size()){
                break; 
            }   
            
            if(now->arr[s[idx] - 'a']->cnt == 1){
                ret++;
                break;
            }
            else{
                now = now->arr[s[idx] - 'a'];
                ret++;
            }
            idx++;
        }
        
        return ret;
    }
    
    void insert(string s){
        
        Node *now = root;
        int idx = 0;
        
        while(1){
            if(idx == s.size()) {
                break;
            }
            
            if(now->arr[s[idx] - 'a'] == NULL){
                now->arr[s[idx] - 'a'] = new Node(s[idx]);
                now = now->arr[s[idx] - 'a'];
            }
            else{
                now = now->arr[s[idx] - 'a'];   
                now->cnt++;
            }
            idx++;
        }
    }
};

trie *t = new trie();

int solution(vector<string> words) {
    int answer = 0;
    
    for(int i=0; i<words.size(); i++){
        t->insert(words[i]);
    }
    
    for(int i=0; i<words.size(); i++){
        answer += t->find(words[i]);
    }
    
    return answer;
}
