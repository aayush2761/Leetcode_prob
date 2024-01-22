class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i] - 1]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (arr[i] == 2) {
                ans.push_back(i + 1);

                // Find the missing number
                int flag=0;
                if(flag==0){
                    for (int j = i - 1; j >=0; j--) {
                    if (arr[j] == 0) {
                        ans.push_back(j + 1);
                        break;
                    }
                }
                flag=1;
                }
               if(flag!=0) {for (int j = i + 1; j < nums.size(); j++) {
                    if (arr[j] == 0) {
                        ans.push_back(j + 1);
                        break;
                    }
                }}

                break;
            }
        }

        return ans;
    }
};
