class Solution {
public:
    string fun(string &res, int n , string num) {
        if (n == 1) return num; 
        string newStr = "";     
        int i = 0;
        

        while (i < num.size()) {
            int count = 1;      
            while (i + 1 < num.size() && num[i] == num[i + 1]) {
                count++;        
                i++;
            }
            newStr += to_string(count) + num[i]; 
            i++;
        }
        return fun(res, n - 1, newStr);
    }

    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";  
        return fun(res, n, res);
    }
};
