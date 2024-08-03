// class Solution {
// public:
//     int solve(string temp,int n,int k){
//         if(n==1){
//             return temp[k-1]-'0';
//         }

//         int len=temp.size();
//         string a="";
//         for(int i=0;i<len;i++){
//             if(temp[i]=='1'){
//                 a+="10";
//             }
//             else{
//                 a+="01";
//             }
//         }
//         return solve(a,n-1,k);

//     }
//     int kthGrammar(int n, int k) {
//         // string t="0";
//         // return solve(t,n,k);
//         if(n==1){return 0;}
//         if(n==2 || n==3){
//             return solve("0", n,k);
//         }
//         string temp="01101001";
//         int noOfTimes=n-4;
//         while(noOfTimes--){
//             string t=temp;
//             reverse(t.begin(),t.end());
//             temp+=t;
//         }
//         return temp[k-1]-'0';
        
//     }
// };
// // class Solution {
// // public:
// //     int kthGrammar(int n, int k) {
// //         string res = "0";
// //         solve(res, n);
// //         return res[k-1] - '0';
// //     }

// // private:
// //     void solve(string &res, int n) {
// //         if (n == 1) return;
// //         string temp = "";
// //         for (int i = 0; i < res.size(); ++i) {
// //             if (res[i] == '0') temp += "01";
// //             else temp += "10";
// //         }
// //         res = temp; 
// //         solve(res, n-1); 
// //     }
// // };
class Solution {
public:
    int kthGrammar(int N, int K) {
	if (N == 1) return 0;
	if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
	else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
    }
};