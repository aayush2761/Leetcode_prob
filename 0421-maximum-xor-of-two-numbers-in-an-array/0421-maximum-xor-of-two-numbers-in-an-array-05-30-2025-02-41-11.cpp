struct trieNode{
    trieNode * child[2];
   trieNode(){
     for(auto &it : child) it=nullptr;
   }
};

class Solution {
public:
    
    void insert(int n, trieNode * root){
        trieNode *pcrawler = root;
        for(int i=31;i>=0;i--){
            int index = (n>>i)&1;
            if(pcrawler->child[index]==nullptr){
                pcrawler->child[index]= new trieNode();
            }
            pcrawler= pcrawler->child[index];
        }
    }
    int search(int n, trieNode * root){
        int answer=0;
        trieNode* pcrawler= root;
        for(int i=31;i>=0;i--){
            long long index= (n>>i) & 1;
            if(index==0 && pcrawler->child[1] != nullptr){
                answer+= (1U<<i);
                pcrawler= pcrawler->child[1];
            }
            else if(index==1 && pcrawler->child[0]!=nullptr){
                answer+=(1U<<i);
                pcrawler= pcrawler->child[0];

            }
            else pcrawler = pcrawler->child[index];

        }
        return answer;
    }
    int findMaximumXOR(vector<int>& nums) {
        // insert 
        trieNode * root= new trieNode();
        for(int i=0;i<nums.size();i++){
            insert(nums[i] , root);
        }
        // search for best answer ;
        int answer=0;
        for(int i=0;i<nums.size();i++){
            int current = search(nums[i],root);
            answer= max(answer, current);
        }
        return answer;
    }
};