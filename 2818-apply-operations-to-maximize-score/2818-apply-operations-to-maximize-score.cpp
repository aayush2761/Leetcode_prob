class Solution {
    int PrimeFactorsCount(int n)
        {
            if(n==1)
            {
                return 0;
            }
            int num = 0;
            if (n % 2 == 0)
            {
                num++;

                while (n % 2 == 0)
                {
                    n /= 2;
                }
            }

            for (int i = 3; i*i <=n; i += 2)
            {
                if (n % i == 0)
                {
                    num++;

                    while (n % i == 0)
                    {
                        n /= i;
                    }
                }
            }

            if (n > 2)
                num++;
            return num;
       }
    int power(long long x, unsigned int y, int p = 1e9+7)
    {
        int res = 1;     // Initialize result

        x = x % p; // Update x if it is more than or
                    // equal to p

        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;

            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>v(n);
        for(int i=0 ; i<n ; i++){
            v[i] = PrimeFactorsCount(nums[i]);
        }
        // distance between Prev least element
        vector<int>left(n,1);
        stack<int>st,s;
        st.push(0);
        for(int i=1 ; i<n ; i++){
            while(!st.empty() && v[i]>v[st.top()]) st.pop();
            if(st.empty()) left[i]  = i+1;
            else left[i] = i - st.top();

            st.push(i);
        }

        // distance between next least element
        vector<int>right(n,1);
        st=s;
        st.push(n-1);
        for(int i=n-2 ; i>=0 ; i--){
            while(!st.empty() && v[i]>=v[st.top()]) st.pop();
            if(st.empty()) right[i] = n-i;
            else right[i] = st.top() - i;
            st.push(i);
         }

        
        
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0 ; i<nums.size() ; i++){
            
            pq.push({nums[i],i});            
        }
        long long ans=1;
        int mod = 1e9+7;
        while(!pq.empty()){
            auto it = pq.top();
            int x= it.second ,y=it.first;
            long long  t = (long long )(left[x]) *(right[x]);
            // cout<<t<<" "<<y<<endl;
            long long  p = min(t,(long long )k);
            k-=p;
            ans=(1ll*ans*power((long long )y,p))%mod;
            ans %= mod;
            if(k<=0) break;
            
            pq.pop();
        }
        return ans;
        
    }
};