// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         int a = num1.size();
//         int b = num2.size();
//         int n = a+b;
//         vector<vector<int>v;
//         int index=n-1;
//         while(b--){
//             vector<int>level(n,0);
//             int carry=0;
//            int num = num2[index]-'0';
//             for(int j=a-1,t=index;j>=0 && t>=0;j-- && t--){
//                 int x= num1[j]-'0';
//                 int p= x*nums;
//                 level[t]=p%10+carry;
//                 carry= p/10;
//             }
//             v.push_back(level);
//             index--;
//         }
//         // addition 
//         string res="";
//         for(int i=0;i<n;i++){
//             int x=0;
//             int carry=0;
//             for(int j=0;j<num2.size();j++){
//                 x+=v[j][i];
//             }
//             res.push_back(x%10);
//             carry= x/10;
//         }
//         // reverse 
//         reverse(res.begin(),res.end());
//         // remove trailing zero
//         int i =0;
//         while(i<n){
//             if(res[i]!='0') return res.substr(i,res.end());
//             i++;
//         }
//         return res;
//     }
// };
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int a = num1.size();
        int b = num2.size();
        int n = a + b;
        vector<vector<int>> v; // Store each level of partial product
        int index = n - 1;

        // Loop through each digit in num2
        for (int i = b - 1; i >= 0; i--) {
            vector<int> level(n, 0); // Initialize a new level with zeros
            int carry = 0;
            int num = num2[i] - '0';
            
            // Multiply each digit in num1 with the current digit in num2
            for (int j = a - 1, t = index; j >= 0; j--, t--) {
                int x = num1[j] - '0';
                int p = x * num + carry;
                level[t] = p % 10; // Store the last digit
                carry = p / 10;    // Update carry
            }
            
            if (carry > 0) {
                level[index - a] = carry; // Store the carry if it exists
            }

            v.push_back(level);
            index--;
        }

        // Addition of all levels
        string res = "";
        int carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            int x = carry;
            for (int j = 0; j < v.size(); j++) {
                x += v[j][i];
            }
            res.push_back((x % 10) + '0'); // Convert to character and add to result
            carry = x / 10;
        }

        // Reverse the result to get the final output
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        // Return the resulting string
        return res.substr(i);
    }
};
