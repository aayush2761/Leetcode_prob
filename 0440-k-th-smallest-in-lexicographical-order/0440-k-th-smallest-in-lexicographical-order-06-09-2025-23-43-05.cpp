struct TrieNode{
    public:
        bool isEnd;
        TrieNode* child[10];
        TrieNode(){
             isEnd=false;
            for(auto & it : child)it=nullptr;
        }
           
};
class Solution {
public:
    void insert(TrieNode* root, string &s){
        TrieNode* crawler= root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'0';
            if(crawler->child[index]==nullptr){
                crawler->child[index]= new TrieNode();
            }
            crawler = crawler->child[index];
        }
        crawler->isEnd=true;
    }
    void dfsSeacrch(TrieNode*root,set<int>&res, int temp,int k){
        if(root==NULL) return;
        if(root->isEnd)res.insert(temp);
        if(res.size()==k) return;
        // for all 10- nodes 
        for(int i=0;i<=9;i++){
            if(root->child[i]){
                // temp = temp*10 + i;
                dfsSeacrch(root->child[i],res,temp*10 + i,k);
            }
        }
    }
    int findKthNumber(int n, int k) {
        TrieNode* root= new TrieNode();
        // insertion 
        set<int>res;
        for(int i=1;i<=n;i++){
            string t= to_string(i);
            insert(root,t );
        }
        // dfs call 
        // vector<int>ans;
        dfsSeacrch(root,res,0,k);
        for(auto it = res.rbegin();it!= res.rend();it--){
            return (int)it;
        }
        return -1;
    }
};