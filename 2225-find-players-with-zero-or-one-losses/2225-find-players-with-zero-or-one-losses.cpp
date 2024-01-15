class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int arr1[100001] = {0};
        int arr2[100001] = {0};

        for(int i = 0; i < matches.size(); i++) {
            arr1[matches[i][1]]++;
            arr2[matches[i][0]]++;
        }

        vector<int> noLose;
        vector<int> oneLose;
        for(int i = 1; i <= 100000; i++) { // Iterate up to the maximum array size
            if (arr1[i] == 1) {
                oneLose.push_back(i);
            } 
            if (arr1[i] == 0 && arr2[i] > 0) {
                noLose.push_back(i);
            }
        }

        vector<vector<int>> ans;
        ans.push_back(noLose);
        ans.push_back(oneLose);

        return ans;
    }
};
