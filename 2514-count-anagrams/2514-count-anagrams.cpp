#define ll long long 
class Solution {
public:
    map<char,int> mp;
    bool flag = false;
    const int M = 1e9 + 7;
    ll powermod(ll x, ll y, ll p) {
        ll res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    ll fact[1000004], modinv[1000004];
    void precomp() {
        modinv[0] = fact[0] = 1;
        for (ll i = 1; i <= 1000000; i++) {
            fact[i] = (fact[i - 1] * i) % M;
            modinv[i] = powermod(fact[i], M - 2, M);
        }
    }
   
    int countAnagrams(string s) {
        if (!flag) {
            precomp();
            flag = true;
        }

        vector<string> v;
        stringstream ss(s);
        string word;

        // Using stringstream for better handling of spaces
        while (ss >> word) {
            v.push_back(word);
        }

        long long res = 1;
        for (int i = 0; i < v.size(); i++) {
            mp.clear();
            for (auto ch : v[i]) 
                mp[ch]++;
            
            long long num = fact[v[i].size()];
            long long deno = 1;
            
            for (auto p : mp) {
                deno = (deno * modinv[p.second]) % M;
            }

            res = (res * ((num * deno) % M)) % M;
        }

        return res;
    }
};
