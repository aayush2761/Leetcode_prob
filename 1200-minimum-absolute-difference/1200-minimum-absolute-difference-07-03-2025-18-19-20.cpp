class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int mini= arr[1]- arr[0];
         for(int i=1;i<arr.size();i++){
            mini= min(mini, arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mini) res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
};