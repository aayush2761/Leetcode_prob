class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // brute force
        // check each interval with all j= i+1 to n interval and before that always check the conditon with the last element of tha naswer array
        // for continous intervals always use map 
        vector<vector<int>>answer;
        // vector<int>diff(10005,0);
        map<int,int>mp;
        for(auto it : intervals){
             mp[it[0]]++;
            mp[it[1]]--;
        }
        int start=0,count=0;;
        for(auto it : mp){
            if(count==0) start = it.first;
            count+= it.second;
            if(count==0){
                answer.push_back({start, it.first});
            }
        }
        return answer;
    }
};