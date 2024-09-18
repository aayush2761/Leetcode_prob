class Solution {
public:
    static bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),compare);

        string ans="";
        vector<vector<int>>res;
        for(auto i : nums){
            vector<int>level;
            if(i==0){
                res.push_back({0});
                continue;
            }
            while(i>0){
                int t= i%10;
                level.push_back(t);
                i/=10;
            }
            
            reverse(level.begin(),level.end());
            res.push_back(level);
        }
        for(auto i : res){
            for(auto j : i){
                ans.push_back((j+'0'));
            }
        }
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};


// class Solution {
// public:
//     struct Compare {
//     bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
//         return a < b; 
//     }
// };
//     string largestNumber(vector<int>& nums) {
//        string ans="";
//         vector<vector<int>>res;
//         for(auto i : nums){
//             vector<int>level;
//             while(i>0){
//                 int t= i%10;
//                 level.push_back(t);
//                 i/=10;
//             }
//             reverse(level.begin(),level.end());
//             res.push_back(level);
//         }
//         //priority queue
//         priority_queue<vector<int>,vector<vector<int>>,Compare>pq;

//         for (auto& vec : res) {
//             pq.push(vec);
//         }
//         while (!pq.empty()) {
//             std::vector<int> v = pq.top();
//             pq.pop();
//             for (int digit : v) {
//                 ans += std::to_string(digit);
//             }
//         }
//         if (ans[0] == '0') {
//             return "0";
//         }

//         return ans;
//     }
// };




//  vector<vector<int>>res;
//         for(auto i : nums){
//             vector<int>level;
//             while(i>0){
//                 int t= i%10;
//                 level.push_back(t);
//                 i/=10;
//             }
//             reverse(level.begin(),level.end());
//             res.push_back(level);
//         }
//         sort(res.rbegin(), res.rend(), [](const std::vector<int>& a, const std::vector<int>& b) {
//         return a[0] < b[0]; // compare 0th element
//     });
//         // print 
//         for(auto i : res){
//             for(auto j : i){
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
//         // now do the rest part 
//         string ans="";
        
//         for(auto i : res){
//             for(auto j : i){
//                 ans.push_back(j);
//             }
//         }
//         return ans;