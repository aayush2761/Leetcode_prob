class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right= s.size();
        while(left<=right){
            // while(((s[left]<'a' || s[left]>'z')&&(s[left]<'A' || s[left]>'Z'))&& left<=right )left++;
            // while(((s[right]<'a' || s[right]>'z')&&(s[right]<'A' || s[right]>'Z'))&& right>=left)right--;
            while(!isalnum(s[left]) && left < right) left++;
            while(!isalnum(s[right]) && right >left) right--;

          if(tolower(s[left]) != tolower(s[right])) return 0;
            left++;
            right--;
        }
        return 1;
    }
};