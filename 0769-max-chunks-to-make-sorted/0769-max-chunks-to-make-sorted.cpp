class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int s=0; 
        int is=0; 
        int ans=0;
        for(int i=0;i<arr.size();i++){
            is+=i;
            s+=arr[i];
            if(is==s){
                ans++;
            }
        }
        return ans;
    }
};