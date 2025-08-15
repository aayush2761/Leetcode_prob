class Solution {
public:
    int merge(int low, int mid, int high, vector<int>&nums){
        int count=0;
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            count += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
        return count;
    }
    int mergeSort(int left, int right, vector<int>&nums){
        if(left>=right) return 0; // base condition 
        int mid = left + (right-left) /2;
        int res=0;
        res+=mergeSort(left, mid,nums);
        res+=mergeSort(mid+1, right,nums);
        res+= merge(left, mid, right,nums);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        return mergeSort(0,n-1,nums);
    }
};