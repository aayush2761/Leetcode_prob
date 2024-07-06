class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int c) {
        long long point = 0;
        // unordered_map<int, int> mp;
        // for (auto i : enemyEnergies) mp[i]++;
        // sort(enemyEnergies.begin(),enemyEnergies.end());
        // int a=0;
        // int b=enemyEnergies.size()-1;
        
        // while (a<=b) {
        //     // int a = small(mp);
        //     // int b = Large(mp);
            
        //     if (c >= enemyEnergies[a]) {
        //         point++;
        //         c -= enemyEnergies[a];
               
        //     } else if (c < enemyEnergies[a] && point >= 1) {
        //         c += enemyEnergies[b];
        //         //mp[b]--;
        //         b--;
        //        // if (mp[b] == 0) mp.erase(b); 
               
        //     } else {
        //         break;
        //     }
        // }
        int mini= *min_element(enemyEnergies.begin(),enemyEnergies.end());
        if(mini>c) return 0;
        long long temp=0;
        for(auto i : enemyEnergies){
            temp+= i;
        }
        temp-=mini;
        temp+=c;


        return temp/mini;
    }

// private:
//     int Large(unordered_map<int, int>& mp) {
//         int temp = INT_MIN;
//         for (auto& i : mp) {
//             if (i.first > temp) {
//                 temp = i.first;
//                 // i.second--;
//             }
//         }
//         return temp;
//     }

//     int Small(unordered_map<int, int>& mp) {
//         int temp = INT_MAX;
//         for (auto& i : mp) {
//             if (i.first < temp) {
//                 temp = i.first;
//             }
//         }
//         return temp;
//     }
};

     


