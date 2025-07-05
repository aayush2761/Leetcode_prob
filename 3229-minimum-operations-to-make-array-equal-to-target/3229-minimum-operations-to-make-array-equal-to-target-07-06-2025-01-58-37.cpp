class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        // ya toh increment hoga ya toh decrement 
        long long increment=0, decrement=0, operations =0;
        for(int i=0;i<nums.size();i++){
            int diff= target[i]-nums[i];
            if(diff>0){
                if(diff>increment){
                    operations+= diff- increment;
                }
                increment= diff;
                decrement=0;
            }
            else{
                if(diff<decrement){
                    operations+= -diff+ decrement;
                }
                decrement= diff;
                increment=0;
            }
        }
        return operations;
    }
};