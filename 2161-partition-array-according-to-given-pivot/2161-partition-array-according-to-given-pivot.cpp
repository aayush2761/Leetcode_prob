class Solution {
public:
    vector<int>p1,p2;
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        p1.clear();
        p2.clear();
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot)p2.push_back(nums[i]);
            else if(nums[i]<pivot) p1.push_back(nums[i]);
            else c++;
        }
        // sort(p1.begin(),p1.end());
        // sort(p2.begin(),p2.end());
        while(c--)p1.push_back(pivot);
        for(int i=0;i<p2.size();i++){
            p1.push_back(p2[i]);
        }
        return p1;
    }
};