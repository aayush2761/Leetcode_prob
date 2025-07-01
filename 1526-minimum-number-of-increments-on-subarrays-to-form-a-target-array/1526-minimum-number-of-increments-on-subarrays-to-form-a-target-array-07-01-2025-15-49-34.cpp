class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        // arr[i]= arr[i-1] + diff[i]  -> array from the difference array 
        vector<int>diff= target;
        for(int i=1;i<n;i++){
            diff[i]= target[i]- target[i-1];

        }
        // for(int i=0;i<n;i++) cout<<diff[i]<<" ";
        // return 0;
        int answer = 0;
         for(auto &it : diff) {
            if(it>0) answer+=it;
         }
         return answer;
    }
};