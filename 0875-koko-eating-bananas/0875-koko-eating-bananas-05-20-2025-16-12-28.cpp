class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1,high = 1e9;
        int res=INT_MAX;
        //  00000000000000111111111111
         auto check = [&](int mid)->bool{
            int count=0;
            for(auto it : piles){
                count+= ((it+mid-1)/mid);
                if(count>h) return 0;
            }
            return 1;
        };
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(check(mid)){
                res= min(res,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
       
        return res;
    }
};