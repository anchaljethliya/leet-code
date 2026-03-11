#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    vector<WordDictionary*> children;
    bool isEndOfWord;

public:
    // Constructor
    WordDictionary() {
        children = vector<WordDictionary*>(26, nullptr);
        isEndOfWord = false;
    }

    // Add word into Trie
    void addWord(string word) {
        WordDictionary* curr = this;

        for(char c : word) {
            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new WordDictionary();
            }

            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }

    // Search word (supports '.')
    bool search(string word) {
        WordDictionary* curr = this;

        for(int i = 0; i < word.length(); i++) {
            char c = word[i];

            // Wildcard case
            if(c == '.') {
                for(auto child : curr->children) {
                    if(child != nullptr && child->search(word.substr(i + 1))) {
                        return true;
                    }
                }
                return false;
            }

            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEndOfWord;
    }
};