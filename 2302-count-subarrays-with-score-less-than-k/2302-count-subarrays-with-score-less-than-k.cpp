class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0,sum=0;
        if(k==0) return count;
    
        for (int i = 0, j = 0; i < nums.size(); ++i) {
        sum += nums[i];
        while (sum * (i - j + 1) >= k)
            sum -= nums[j++];
        count += i - j + 1;
    }
        return  count;
    }
};




//157/167 case passed 
// long long count=0;
//         if(k==0) return count;
    
//         long long j=0;
//        while(j<nums.size()){
//         if(nums[j]<k) count++;
//         else{
//             j++;
//             continue;
//         }
//         long long temp=nums[j];
//         long long i=j+1;
//         while(i<nums.size()){
//             temp+=nums[i];
//             if(temp*(i-j+1)<k)count++;
//             else break;
//             i++;
//         }
//         j++;
//        }
//         return  count;