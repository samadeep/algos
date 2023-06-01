// Runtime : 583 ms 

class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    
    struct TN{
        TN* n[26];
        bool end;
        TN(){
            for(int i=0;i<26;++i){
                n[i]=NULL;
            }
            end=false;
        }
        ~TN(){
            for(TN* t:n){
                delete t;
            }
        }
    };
    
    TN *root;
    
    WordDictionary() {
        root=new TN();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        const char *c=word.c_str();
        TN* r=root;
        while(*c!='\0'){
            int cc=*c-'a';
            //cout<<r<<"\n";
            //cout<<cc<<"\n";
            if(r->n[cc]==NULL){
                r->n[cc]=new TN();
            }
            c++;
            r=r->n[cc];
        }
        r->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    
    bool search(const char *c, TN* r){
        while(*c!='\0'){
            int cc=*c-'a';
            ++c;
            if(cc>=0){
                if(r->n[cc]==NULL){
                    return false;    
                }
                r=r->n[cc];
            }
            else{
                for(int i=0;i<26;++i){
                    if(r->n[i]!=NULL){
                        if(search(c,r->n[i])){
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return r->end;
    }
    
    bool search(string word) {
        return search(word.c_str(),root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
