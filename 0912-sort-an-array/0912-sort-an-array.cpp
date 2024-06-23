class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // soving using heaps 
        // using min heap  bhai 
        priority_queue<int, vector<int>, greater<int>>minH;
        for(auto i :  nums){
            minH.push(i);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]= minH.top();
            minH.pop();
        }
        return nums;
    }
};