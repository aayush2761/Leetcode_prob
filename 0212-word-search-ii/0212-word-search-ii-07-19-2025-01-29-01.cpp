class Solution {
public:
    vector<string>res;
    struct trieNode{
        bool isEnd;
        trieNode *child[26];
        string word;
        trieNode(){
            isEnd=false;
            word="";
            for(auto &it : child ) it = nullptr;
        }
    };
    trieNode * root= new trieNode();
    // insert
    void insert(string s){
        trieNode* crawler = root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'a';
            if(crawler->child[index]!= nullptr){
                crawler= crawler->child[index];
            }
            else {
                // new node 
                crawler->child[index]= new trieNode();
                 crawler= crawler->child[index];
            }
        }
        crawler->isEnd= true;
        crawler->word=s;
    }
    // search 
    string search( string s){
        trieNode* crawler = root;
        for(int i=0;i<s.size();i++){
            int index = s[i]-'a';
            if(crawler->child[index]==nullptr) return "";
            crawler= crawler->child[index];
        }
         if(crawler->isEnd) return crawler->word;
         return "";
    }
    // bool startsWith(string prefix) {
    //     TrieNode *crawler = root;
    //     for(auto &it : prefix){
    //         int index= it-'a';
    //         if(!crawler->child[index]){
    //             // crawler->child[i]=new TrieNode();
    //             return false;
    //         }
    //         crawler = crawler->child[index];
           
    //     }
    //      return true;
    // }
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board,int i, int j, trieNode*root){
            char ch = board[i][j];
            if(ch=='#' || !root->child[ch-'a']) return;
            root= root->child[ch-'a'];
            if(root->word.size()>0){
                res.push_back(root->word);
                root->word="";
            }
            board[i][j]='#';
            for(auto &d : dir ){
                int ni= i+ d[0];
                int nj= j+ d[1];
                if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size())dfs(board, ni, nj, root);
            }
            // backtrack
            board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // trieNode * root = new trieNode();
        // insert
        res.clear();
        for(auto &it : words){
            insert( it);
        }
        int n=board.size();
        int m = board[0].size();
        // vector<string>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,i,j,root);
            }
        }
        return res;
    }
};