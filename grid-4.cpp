#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() {
        children.clear();
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int len = word.size();
        for (int i = 0; i < len; i++) {
            if (curr->children[word[i]]) curr = curr->children[word[i]];
            else {
                TrieNode* newNode = new TrieNode();
                curr->children[word[i]] = newNode;
                curr = curr->children[word[i]];
            }
            if (i == len - 1) curr->isEnd = true;
        }
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c] == nullptr) return false;
            curr = curr->children[c];
        }
        if (!curr->isEnd) return false;
        else return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children[c] == nullptr) return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */