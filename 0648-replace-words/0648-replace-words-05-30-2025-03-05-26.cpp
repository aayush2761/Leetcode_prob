struct trieNode{
    bool isEnd;
    int index;
    trieNode * child[26];
    trieNode(){
        isEnd=false;
        index = -1;
        for(auto &it : child) it=nullptr;
    }
};
class Solution {
public:
    void insert(string s, trieNode * root, int idx){
        trieNode* crawler = root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'a';
            if(crawler->child[index]==nullptr){
                crawler->child[index]= new trieNode();
            }
            crawler= crawler->child[index];
        }
        crawler->isEnd=true;
        crawler->index=idx;
    }
    int search(string s, trieNode* root){
         trieNode* crawler = root;
        for(int i=0;i<s.size();i++){
            int index= s[i]-'a';
            if(crawler->child[index]==nullptr){
                return -1;
            }
             crawler= crawler->child[index];
            if(crawler->isEnd){
                return crawler->index;
            }
           
        }
        return -1;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        trieNode * root= new trieNode();
        

        // insert
        for(int i=0;i<dictionary.size();i++ ){
            insert(dictionary[i], root,i);
        }
        // searching 
        string result="";
        int i=0,j=0;
        while(i<sentence.size()){
            if(sentence[i]==' '){
                string temp = sentence.substr(j, i-j+1);
                int index = search(temp,root);
                if(index==-1) {
                    result+=temp;
                   
                }
                else {result+= dictionary[index];
                 result+=" ";}
                // 
                j=i+1;
            }
            i++;
        }
        // last string 
        string temp = sentence.substr(j, i-j+1);
                int index = search(temp,root);
                if(index==-1) result+=temp;
                else result+= dictionary[index];
                
        return result;
    }
};