class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // variable size partioning in os same concept 
        priority_queue<int,vector<int>,greater<int>>pq1(players.begin(), players.end()), pq2(trainers.begin(), trainers.end());
        int count=0;
        while(!pq1.empty() && !pq2.empty()){
            int t1= pq1.top();
            int t2=pq2.top();
            if(t1<=t2){
                pq1.pop();
                pq2.pop();
                count++;
            }
            else{
                pq2.pop();
            }
        }
        return count;

    }
};