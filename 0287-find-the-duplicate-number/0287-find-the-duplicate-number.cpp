class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int arr[100001]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(arr[i]>=2){
                return i;
                break;
            }
        }
        return 0;
    }
};