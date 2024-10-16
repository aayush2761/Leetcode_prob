class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>track;
        int fsize = flowers.size();
         // Add +1 for start and -1 for end+1
        for(int i=0;i<fsize;i++)
        {
            track[flowers[i][0]]++;
            track[flowers[i][1]+1]--;
        }
        int prevCount = 0;
        for(auto &iter : track)
        {
            iter.second += prevCount;
            prevCount = iter.second;
        }
        
        vector<int>res;
        int count;
        
        // binary search to get flower count in ith day
        for(int i=0;i<people.size();i++)
        {   
            auto iter = track.lower_bound(people[i]);
            count = (iter->first == people[i]) ? iter->second : ((iter==track.begin()) ? 0 : prev(iter)->second);
            
            res.push_back(count);
        }
        
        return res;
    }
};


// ----> BRUTE FORCE LST   MLE INCOMING   <--------------------------//
// class Solution {
// public:
//     vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
//         unordered_map<int,int>mp;
//         // 
//         for(auto i : flowers){
            
//             int a = i[0];
//             int b= i[1];
//             while(a<=b) {
//                 mp[a]++;
//                 a++;
//             }
//         }
//         // map 
//         vector<int>res;
//         for(auto i : people){
//             res.push_back(mp[i]);
//         }
//         return res;
//     }
// };