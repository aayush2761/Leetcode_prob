// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         int p=0;
//         for(int i=0;i<target.size();i++){
//             p^=target[i]^arr[i];
//         }
//         if(p==0) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> count(1001, 0); 
        for (int num : target) count[num]++;
        for (int num : arr) count[num]--;
        
        for (int c : count) {
            if (c != 0) return false;
        }
        
        return true;
    }
};
