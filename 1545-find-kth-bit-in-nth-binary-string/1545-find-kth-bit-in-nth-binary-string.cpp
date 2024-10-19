class Solution {
public:
    string result(int n, string &res) {
        if (n == 0) return res;
        
        string temp = res;
        temp.push_back('1');
        
        // Create the inverted version of the current res
        string inv = "";
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0') inv.push_back('1');
            else inv.push_back('0');
        }
        
        // Reverse the inverted string and append it to temp
        reverse(inv.begin(), inv.end());
        
        // Set res as the newly generated string
        res = temp + inv;
        
        return result(n - 1, res);
    }

    char findKthBit(int n, int k) {
        string res = "0";
        result(n - 1, res);
        return res[k - 1];
    }
};
