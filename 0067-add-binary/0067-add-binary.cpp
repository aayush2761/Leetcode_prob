// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int n = a.size();
//         int m= b.size();
//         int i=n-1;
//         int j=m-1;
//         string res="";
//         char carry='0';
//         while(i>=0 || j>=0){
//             char p,q;
//             if(i>=0) p=a[i];
//             else p='0';
//             if(j>=0) q=b[i];
//             else q='0';
//             if(p=='1' && q=='1'){
                
//                 if(carry=='1')res.push_back('0');
//             }
//         }
//     }
// };
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};