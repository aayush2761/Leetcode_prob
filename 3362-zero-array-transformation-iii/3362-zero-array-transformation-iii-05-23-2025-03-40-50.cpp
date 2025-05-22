class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0;
        int n = nums.size();
        int q= queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        int index=0;
        for(int i=0;i<n;i++){
            while(index<q && queries[index][0]==i){
                maxHeap.push(queries[index][1]);
                index++;
            }
           
            nums[i]-=minHeap.size();

            while(nums[i]>0 && maxHeap.size()>0 && maxHeap.top()>= i){
                int ending= maxHeap.top();
                maxHeap.pop();
                nums[i]--;
                minHeap.push(ending);
                res++;
            }
            if(nums[i]>0) return -1;

             while(!minHeap.empty() && i>=minHeap.top()){
                minHeap.pop();
            }

        }
        return q-res;
    }
};