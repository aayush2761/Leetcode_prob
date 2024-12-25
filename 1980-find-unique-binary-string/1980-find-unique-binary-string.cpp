class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            string binary = "";
            for (int j = n - 1; j >= 0; j--) {
                binary += (i & (1 << j)) ? '1' : '0';
            }
            if(st.find(binary)==st.end())return binary;
        }
        return "";
    }
};