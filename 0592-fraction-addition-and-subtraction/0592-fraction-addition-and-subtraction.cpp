// class Solution {
// public:
//     string fractionAddition(string s) {
//         int lcmm=1;
//         // neg 
//         if(s[0]=='-'){
//             for(int i=3;i<s.size();i+=4){
//                 lcmm = lcm(s[i]-'0',lcmm);
//             }
//         }
//         // pos
//         else{
//             for(int i=2;i<s.size();i+=4){
//                 lcmm = lcm(s[i]-'0',lcmm);
//             }

//         }
//         // we got the lcm 
//         // neg 
//         int num=0;
//         if(s[0]=='-'){
//             for(int i=1;i<s.size();i+=4){
//                 if(s[i]=='-'){
//                     num+= -1*(lcmm/(s[i+1]-'0'))*(s[i]-'0');
//                 }
//                 else{
//                      num+=(lcmm/(s[i+1]-'0'))*(s[i]-'0');
//                 }
//             }
//         }
//         // pos 
//         else{
//             for(int i=0;i<s.size();i+=4){
//                 if(s[i]=='-'){
//                     num+= -1*(lcmm/(s[i+1]-'0'))*(s[i]-'0');
//                 }
//                 else{
//                      num+=(lcmm/(s[i+1]-'0'))*(s[i]-'0');
//                 }
//             }
//         }

//         // we got num as numerator ans lcmm as deno 
//         if(num<lcmm){
//             return to_string(num)+"/"+to_string(lcmm);
//         }
//         else if(num==lcmm) return "1/0";
//         else{
//             if(num%lcmm==0){
//                 num/=lcmm;
//                 return to_string(num)+"/"+to_string(lcmm);

//             }
//             else return to_string(num)+"/"+to_string(lcmm);
//         }
//         return "";
//     }
// };
class Solution {
public:
    string fractionAddition(string s) {
        int lcmm = 1; // Initialize the LCM to 1

        // Calculate LCM of all denominators
        for (int i = 0; i < s.size(); ) {
            // Find the denominator, skip signs
            if (s[i] == '-' || s[i] == '+') {
                i++;
            }
            
            // Skip the numerator
            while (isdigit(s[i])) {
                i++;
            }

            // Move past '/'
            i++;

            // Extract denominator
            int denominator = 0;
            while (i < s.size() && isdigit(s[i])) {
                denominator = denominator * 10 + (s[i] - '0');
                i++;
            }

            // Calculate LCM
            lcmm = lcm(lcmm, denominator);
        }

        // We got the LCM
        int num = 0; // Initialize numerator sum

        // Calculate the adjusted numerator sum
        for (int i = 0; i < s.size(); ) {
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }

            // Extract numerator
            int numerator = 0;
            while (isdigit(s[i])) {
                numerator = numerator * 10 + (s[i] - '0');
                i++;
            }

            // Move past '/'
            i++;

            // Extract denominator
            int denominator = 0;
            while (i < s.size() && isdigit(s[i])) {
                denominator = denominator * 10 + (s[i] - '0');
                i++;
            }

            // Adjust numerator to common denominator
            num += sign * (numerator * (lcmm / denominator));
        }

        // We got num as numerator and lcmm as denominator
        int gcd_val = gcd(abs(num), lcmm);
        num /= gcd_val;
        lcmm /= gcd_val;

        // Return the result
        return to_string(num) + "/" + to_string(lcmm);
    }
};
