class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    //   next_permutation(nums.begin(),nums.end());
    int n = nums.size();
    int ind=-1;
    for(int i =n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(nums.begin(),nums.end());
        return ;
    }
    // search for nearest largest
    int ind2=-1;
    for(int i=n-1;i>ind;i--){
        if(nums[ind]<nums[i]){
            ind2=i;
            break;
        }
    }
    // swap 
    swap(nums[ind], nums[ind2]);
    reverse(nums.begin()+ind+1, nums.end());




    }
};



// STL SOLUTION 
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//       next_permutation(nums.begin(),nums.end());

//     }
// };