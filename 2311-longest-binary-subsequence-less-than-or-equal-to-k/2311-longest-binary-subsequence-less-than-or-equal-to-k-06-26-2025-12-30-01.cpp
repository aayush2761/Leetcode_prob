class Solution {
public:
    bool check(int mid, string s, int k, int n){
         long long value = 0;
       int taken=0;
        for(int i=n-1;i>=0;i--){
            if(taken>=mid) return 1;
            if(s[i]=='0')taken++;
            else {
                if(taken>=35) continue;
                if(value + (1LL<<taken)<=k){
                    value+= (1LL<<taken);
                    taken++;
                }
            }
        }
        return taken>=mid;

    }
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int low =0, high = n;
        int answer=0;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(check(mid, s, k, n)){
                answer= mid;
                low= mid+1;
            }
            else high= mid-1;
        }
        return answer;
    }
};