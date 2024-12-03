// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int res=0,i=0;
//         while(i<b.size()){
//             int j=0;
//             int n = a.size();
//             if(b[i]==a[j]){
//                 if(i!=0) res++;
//                 while(b[i]==a[j] && i<b.size()){
//                 if(j+1==n) res++;
//                 j=(j+1)%n;
//                 i++;

//                 }
//                 if(i<b.size() || j+1<a.size())res++;
            
//             }
//             else i++;
//         }
//         return res ==0 ? -1 : res;
//     }
// };

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int res = 0;
        while (repeated.size() < b.size()) {
            repeated += a;
            res++;
        }
        if (repeated.find(b) != string::npos) return res;
        repeated += a;
        res++;
        if (repeated.find(b) != string::npos) return res;
        return -1;
    }
};
