class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p=0;
    for (int i = 0; i < t.length() and p < s.length(); i++)
        if (s[p] == t[i])
            p++;
 
        if(p==s.size())return true;
        return false;
    }
};

//jb s ka index t ke sath milega tabhi s ke index ko badhana 