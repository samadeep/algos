

#### Trie Template Code :
Link : https://leetcode.com/problems/implement-trie-prefix-tree/

```cpp
struct TrieNode {
    TrieNode* links[26];
    bool isWord;

    // Constructor: Initialize links to nullptr and isWord to false
    TrieNode() : isWord(false) { 
        std::fill(std::begin(links), std::end(links), nullptr);
    }
};

class Trie {
public:
    TrieNode* root;

    // Constructor: Create the root node
    Trie() : root(new TrieNode()) {}

    // Destructor: Recursively delete all nodes to prevent memory leaks
    ~Trie() { 
        deleteTrie(root); 
    }

    void insert(const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->links[index]) {
                curr->links[index] = new TrieNode();
            }
            curr = curr->links[index];
        }
        curr->isWord = true; // Mark the end of a word
    }

    bool search(const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->links[index]) return false;
            curr = curr->links[index];
        }
        return curr->isWord; // Check if it's a complete word
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->links[index]) return false;
            curr = curr->links[index];
        }
        return true; 
    }

private:
    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (TrieNode* child : node->links) {
            deleteTrie(child);
        }
        delete node;
    }
};
```

