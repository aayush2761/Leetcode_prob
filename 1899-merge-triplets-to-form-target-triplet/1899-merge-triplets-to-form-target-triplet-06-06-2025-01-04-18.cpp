class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>>required;
        for(auto & it : triplets){
            if(it[0]<=target[0] && it[1]<=target[1] && it[2]<=target[2] )required.push_back(it);
        }
        bool flag1= false,flag2=false, flag3=false;
        for(auto &it : required){
            if(!flag1){
                if(it[0]== target[0])flag1=true;
                
            }
            if(!flag2){
                if(it[1]== target[1])flag2=true;
                
            }
            if(!flag3){
                if(it[2]== target[2])flag3=true;
                
            }
            if(flag1 && flag2 && flag3) return 1;
        }
        return 0;
    }
};