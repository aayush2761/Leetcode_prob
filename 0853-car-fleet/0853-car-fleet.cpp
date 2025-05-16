class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<double, vector<double>,greater<double>>pq;
        vector<pair<int,double>>v;
        for(int i=0;i<speed.size();i++){
            double x= ((target-position[i])*1.0)/(speed[i]*1.0);
            pq.push(x);
            v.push_back({position[i],x});
        }
        sort(v.begin(),v.end(),[&](auto a , auto b){
            return a.first>b.first;
        });
        int res=0;
        double prev=-1;
         for(int i=0;i<speed.size();i++){
            if(v[i].second==prev)continue;
            if(pq.top()>v[i].second)continue;
            while(!pq.empty()&& pq.top()<v[i].second){
                pq.pop();
            }
            prev= v[i].second;
            // cout<<v[i].first<<endl;
            res++;
         }
         return res;

    }
};