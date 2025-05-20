class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0, high =n-1;
        while(low<high){
            if(nums[low]<nums[high])break;
            int mid = low + (high-low) /2;
            if(nums[mid]>=nums[low])low=mid+1;
            else high= mid;
        }
        // cout<<low<<endl;
        // index -> low 
        auto check= [&](vector<int>&temp)->int{
            int l=0,h=temp.size()-1;
            while(l<=h){
                int m= l + (h-l) /2;
                if(temp[m]==target)return m;
                else if (temp[m]>target)h=m-1;
                else l = m+1;
            }
            return -1;
        };
        vector<int>temp1(nums.begin(), nums.begin()+low);
        // for(int i=0;i<temp1.size();i++)cout<<temp1[i]<<" ";
        int index= check(temp1);
        if(index!=-1)return index;
         vector<int>temp2( nums.begin()+low,nums.end());
        //  cout<<endl;
         for(int i=0;i<temp2.size();i++)cout<<temp2[i]<<" ";
         int index1= check(temp2);
       return index1==-1 ? -1 : temp1.size()+index1;

    }
};