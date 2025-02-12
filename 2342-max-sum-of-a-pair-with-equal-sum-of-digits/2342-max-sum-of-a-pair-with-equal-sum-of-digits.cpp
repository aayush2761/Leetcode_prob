class Solution {
public:
    int check(int n) {
        int x = 0;
        while (n > 0) { 
            x += n % 10;
            n /= 10;
        }
        return x;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int num : nums) {
            mp[check(num)].push_back(num);
        }
        int res = -1; 
        for (auto& [_, temp] : mp) {
            if (temp.size() < 2) continue; 
            sort(temp.begin(), temp.end());
            res = max(res, temp[temp.size() - 1] + temp[temp.size() - 2]);
        }
        return res;
    }
};
