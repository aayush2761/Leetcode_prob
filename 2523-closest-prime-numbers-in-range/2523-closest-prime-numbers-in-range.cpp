#define ll long long
class Solution {
public:
    Solution(){
        Sieve(1e6+2);
    }
    vector <bool> is_prime;
    bool flag= true;
// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
    vector<int> closestPrimes(int left, int right) {
        // if(flag){
        //     Sieve(10000002);
        //     flag=false;
        // }
       int a = -1, b = -1, diff = INT_MAX;
        int res1 = -1, res2 = -1;
        int i = left;
       while (i <= right) {
            if (is_prime[i]) {
                if (a == -1) { 
                    a = i;  // First prime found
                } else {
                    b = i;  // Second prime found
                    if (b - a < diff) { 
                        diff = b - a;  // Update minimum difference
                        res1 = a, res2 = b;
                    } 
                    a = b;  // Update `a` for the next possible pair
                }
            }
            i++;
        }

        return (res1 == -1 || res2 == -1) ? vector<int>{-1, -1} :vector<int>{res1, res2};
    }
};