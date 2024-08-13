#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int count;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void add(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++;
        }
    }

    int find(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return 0;
            }
            node = node->children[index];
        }
        return node->count;
    }
};

int main() {
    Trie trie;
    int n;
    cin>>n;
    string operations;
    vector<int> result;
    for(int i=0;i<n+1;i++){
        getline(cin,operations);
        if (operations.substr(0, 3) == "add") {
            string word = operations.substr(4);
            trie.add(word);
        } else if (operations.substr(0, 4) == "find") {
            string prefix = operations.substr(5);
            result.push_back(trie.find(prefix));
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
