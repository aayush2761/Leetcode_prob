struct trieNode{
    bool isEnd;
    trieNode* child[26];
    trieNode(){
        isEnd=false;
        for(auto &it: child)it=nullptr;
    }
};
class WordDictionary {
public:
    trieNode * root;
    WordDictionary() {
        root= new trieNode();
    }
    
    void addWord(string s) {
         trieNode* crawler= root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'a';
            if(crawler->child[index]==nullptr){
                crawler->child[index]= new trieNode();
            }
            crawler= crawler->child[index];
        }
        crawler->isEnd=true;
    }
    bool searchHelper(trieNode* root, string s){
          trieNode* crawler= root;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->child[j]!=nullptr && searchHelper(crawler->child[j], s.substr(i+1))) return true;
                }
                return false;
            }
            int index= s[i]-'a';
            if(crawler->child[index]==nullptr){
                return false;
            }
            crawler= crawler->child[index];
        }
        return crawler->isEnd;
    }
    bool search(string s) {
        //  trieNode* crawler= root;
        // for(int i=0;i<s.size();i++){
        //     int index= s[i]-'a';
        //     if(crawler->child[index]==nullptr){
        //         return false;
        //     }
        //     crawler= crawler->child[index];
        // }
       return searchHelper(root, s);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */