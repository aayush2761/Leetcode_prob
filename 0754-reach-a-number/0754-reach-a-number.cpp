class Solution {
public:
    int reachNumber(int target) {
         target=abs(target);
        // minimum number of moves required 
        // monotonic fuction 
        // FFFFFFFFFFFFFFFFTTTTTTTTTTTTTT
        // Binary search 
        long long min_moves=0;
        int low= 1 ;
        int high = 100000;
        while(low<=high){
            long long  mid = low  + (high-low) /2;
            // code 
            long long dis=(mid*(mid+1))/2;
            if(dis>=target && (dis-target)%2==0){
                    min_moves=mid;
                }
            if(dis<target) low++;
            else high--;
        }
        return (int)min_moves;
    }
};