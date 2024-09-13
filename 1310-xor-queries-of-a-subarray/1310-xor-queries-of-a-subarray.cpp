class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            int temp=0;
            int start=queries[i][0];
            int end= queries[i][1];
            while(start<=end){
                // if(start==i) continue;
                temp^=arr[start];
                start++;
            }
            res.push_back(temp);
        }
        return res;
    }
};