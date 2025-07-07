// struct comp{
//     bool operator()(const pair<int,int>&a, const pair<int,int>&b){
//         if(a.second!= b.second) return a.second>b.second;
//         return a.first>b.first;
//     }
// };
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // maximum one events in a day 
        sort(events.begin(), events.end());
        priority_queue<int,vector<int>, greater<int>>pq;
        int i=0, n= events.size(), day=events[0][0];
        int answer=0;
        while(!pq.empty() || i<n){
            if(pq.empty())day=events[i][0];
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            // answer part 
           if(!pq.empty()){
                pq.pop();
                answer++;
           }


           day++;

            // skip day < current day 
            while(!pq.empty() && pq.top()<day)pq.pop();

        }
        return answer;
      
    }
};


// sort(events.begin(), events.end(), [](const vector<int>&a, const vector<int>&b){
//             if(a[1]!= b[1]) return a[1]<b[1];
//             return a[0]<b[0];
//         }); // sort it based on the expiry date 
//         int index =0;
//         int time =1;
//         int maxi=0;
//         for(auto &it: events) {
//             maxi= max(maxi, it[0]);
//             maxi= max(maxi, it[1]);
//         }
//         int answer=0;
//         while(time<= maxi && index<events.size()){
//             if(time>= events[index][0] && time<= events[index][1]){
//                 answer++;
//                 index++;
//             }
//             time++;
//         }
//         return answer;