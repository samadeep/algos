

#### Trie Template Code :
Link : https://leetcode.com/problems/implement-trie-prefix-tree/

```cpp
struct TrieNode
{
    // Array of 26 Links
    TrieNode* links[26];
    bool isWord;
    TrieNode()
    {
        for( int i = 0 ; i < 26 ; i++ ) links[i] = NULL;
        isWord = false;
    }
};

class Trie {
public:

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode* curr = root;
        for( auto c : word )
        {
            if( curr -> links[c-'a'] == NULL )  curr->links[c-'a'] = new TrieNode();
            curr = curr -> links[c-'a'];
        }
        curr -> isWord = true;
    }

    bool search(string word) {
        
        TrieNode* curr = root;
        for( auto c : word )
        {
            if( curr -> links[c-'a'] == NULL )  return false;
            curr = curr -> links[c-'a'];
        }
        return curr -> isWord;
    }
    
    bool startsWith(string prefix) {

        TrieNode* curr = root;
        for( auto c : prefix )
        {
            if( curr -> links[c-'a'] == NULL )  return false;
            curr = curr -> links[c-'a'];
        }
        return true;
    }
};
```

