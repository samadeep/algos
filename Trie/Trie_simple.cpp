// Each Node has 26 Links mapped to NULL 



struct TrieNode{
    
    TrieNode *link[26];
    bool flag;

    TrieNode()
    {
        flag=false;
        memset(link, 0, sizeof(link));
    }
};


class WordDictionary {
public:
    TrieNode* root=new TrieNode();
    WordDictionary() {
        // root=new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr=root;
        int n=word.size();
        int k=0;

        for(int i=0;i<n;i++)
        {
            k=word[i]-'a';
            if(curr->link[k]==NULL)
            {
                curr->link[k]=new TrieNode();
            }
            // else
            curr=curr->link[k];
        }
        curr->flag=true;
        
    }
    
    bool search(string word) {
        return search(word,root);
    }

    bool search(string word,TrieNode* node)
    {
        int n=word.size();

        int k=0;
        TrieNode* curr=node;
        // if(curr==NULL) return false;

        for(int i=0; i<n and curr ;i++)
        {
            k=word[i]-'a';
           
            if(word[i]=='.')
            {
                if(i==n) return false;

                TrieNode* temp=curr;

                for(int j=0;j<26;j++)
                {
                    curr=temp->link[j];
                    if(search(word.substr(i+1),curr)) return true;
                }

            }
            else
            {
                curr=curr->link[k];
            }
        }

        return curr and curr->flag;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
