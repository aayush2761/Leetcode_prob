class Solution {
public:
    int dayOfYear(string s) {
        map<int, int> mp;
        mp[1] = 31;
        mp[2] = 31 + 28; // February (non-leap year)
        mp[3] = 31 + mp[2];
        mp[4] = 30 + mp[3];
        mp[5] = 31 + mp[4];
        mp[6] = 30 + mp[5];
        mp[7] = 31 + mp[6];
        mp[8] = 31 + mp[7];
        mp[9] = 30 + mp[8];
        mp[10] = 31 + mp[9];
        mp[11] = 30 + mp[10];
        mp[12] = 31 + mp[11];

        int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        int month = (s[5] - '0') * 10 + (s[6] - '0');
        int day = (s[8] - '0') * 10 + (s[9] - '0');
        
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int feb = leap ? 29 : 28;

        if (leap && month > 2) {
            return day + mp[month - 1] + 1;
        } else if (month == 1) {
            return day;
        }
        return day + mp[month - 1];
    }
};
