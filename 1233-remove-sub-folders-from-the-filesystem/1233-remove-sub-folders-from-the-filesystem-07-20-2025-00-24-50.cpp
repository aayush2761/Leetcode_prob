class Solution {
public:
    struct trieNode{
        bool isEnd;
        trieNode *child[27];
        trieNode(){
            for(auto &it : child){
                isEnd= false;
                it= nullptr;
            }
        }
    };
    // insert 
    bool insert(trieNode* root, string &s){
        trieNode *crawler = root;
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1 && s[i]=='/'  && crawler->isEnd){
                return false;
            }
            int index;
            if(s[i]=='/') index= 26;
            else index= s[i]-'a';
            if(crawler->child[index]==nullptr) crawler->child[index]=new trieNode();
            crawler= crawler->child[index];
        }
        crawler->isEnd= true;
        return 1;
    }
    // seacrh 
    // bool search(trieNode* root, string &s){
    //      trieNode crawler = root;
    //     for(int i=0;i<s.size();i++){
    //         int index;
    //         if(s[i]=='/') index= 26;
    //         else index= s[i]-'a';
    //         if(crawler->child[index]==nullptr) crawler->child[index]=new trieNode();
    //         crawler= crawler->child[index];
    //         if(i<s.size()-1)
    //     }
    //     crawler->isEnd= true;
    // }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string>res;
        trieNode *root = new trieNode();
        for(auto &it : folder){
            if(insert(root, it))  res.push_back(it);
        }
        return res;
    }
};