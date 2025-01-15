class Solution {
public:
    int check(int mid, string &s, int k, int n) {
        map<char, int> mp;
        int i = 0, l = 0;
        while (i < n) {
            mp[s[i]]++;
            if (i - l + 1 == mid) {
                // most frequent character count
                int maxi = 0;
                for (auto j : mp) {
                    maxi = max(maxi, j.second);
                }
                //validity
                int count = (i - l + 1) - maxi;
                if (count <= k) return 1;
                // Slide window
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            i++;
        }
        return 0;
    }
    int characterReplacement(string s, int k) {
        // maximum window size is possible or not 
        // 111111100000000  -> binARY Search 
        if(s.size() == 0){
            return 0;
        }
        int n = s.size();
        int lo = 1;
        int hi = n;
        
        int ans = lo;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid,s,k,n)){//true
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        
        return ans;
    }
};