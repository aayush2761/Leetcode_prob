class Solution {
public:
    int halveArray(vector<int>& nums) {
        int res=0;
        double t= 0.0;
      
        priority_queue<double>pq;
        for(auto & i : nums){
            pq.push(i);
            t+=i;
        }
          double half=t/2.0;
        // int res=0;
        double total=0.0;
        while(total<half){
            double x = pq.top();
            pq.pop();
            double m = x/2.0;
            pq.push(m);
            res++;
            total+=m;
           
        }
        // if(total<half) return res-1;
        return res;
    }
};