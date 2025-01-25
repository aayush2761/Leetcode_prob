class Solution 
{
public:
    vector<int>lexicographicallySmallestArray(vector<int>&v,int limit) 
    {
        vector<pair<int,int>>res;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            res.push_back({v[i],i}); 
        }
        sort(res.begin(),res.end()); 
        int l=0;
        vector<int>ans(n,0);
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(res[0].second);
        int r=1;
        while(r<n)
        {
            while(r<n && abs((res[r].first)-(res[r-1].first))<=limit)
            {
                pq.push(res[r].second);
               r++;
            }
            while(!pq.empty())
            {
                ans[pq.top()]=res[l].first;
                l++;
                pq.pop();
            }
            if(r<n)
            {
                pq.push(res[r].second);
               r++;
            }
        }
        if(!pq.empty())
        {
           ans[pq.top()]=res[r-1].first;
           pq.pop();
        }
        return ans;
    }
};