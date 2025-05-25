class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        vector<int>incomingDegree(numCourses,0);
        for(auto it :prerequisites ){
            int a= it[0];
            int b= it[1];
            adj[b].push_back(a);
            incomingDegree[a]++;
        }
        int count=0;
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (incomingDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int element = q.front();
            q.pop();
            count++;
            for (auto it : adj[element]) {
                incomingDegree[it]--;
                if (incomingDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == numCourses;

    }
};