struct trieNode{
    bool isEnd;
    trieNode* child[26];
    trieNode(){
        isEnd=false;
        for(auto &it: child)it=nullptr;
    }
};
class Solution {
public:
    void insert(string s , trieNode* root){
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
    bool search(string s, trieNode* root){
        trieNode* crawler= root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'a';
            if(crawler->child[index]==nullptr){
                return false;
            }
            crawler= crawler->child[index];
        }
        return crawler->isEnd;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trieNode* root= new trieNode();
        for(auto & it : wordDict){
            insert(it,root);
        }
        // int i=0,j=0;
        // while(i< s.size()){
        //     string temp = s.substr(j, i-j+1);
        //     if(search(temp,root)){
        //         j=i+1;
        //     }
        //     i++;
        // }
        // if(j>=s.size()) return true;
        // return false;
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        
        for(int len=1; len<=s.size(); len++){
            for(int i=0; i<len; i++){
                if(dp[i] && search(s.substr(i, len-i),root))
                    dp[len]=true;
            }
        }
        return dp[s.size()];
    }
};



// s =
// "aaaaaaa"
// wordDict =
// ["aaaa","aaa"]