class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        while(i<start.size()&& j<target.size()){
            while (i < start.size() && start[i] == '_') i++;
            while (j < target.size() && target[j] == '_') j++;

            if (i == start.size() || j == target.size()) break;
            if (start[i] != target[j]) return false;

            // left case
            if(start[i]==target[j]&& i<j && start[i]=='L')return false;
            if(start[i]==target[j]&& i>j && start[i]=='R')return false;
            i++;
            j++;
           
        }
        while (j < target.size()) {
            if (target[j] != '_') return false;
            j++;
        }
        while(i<start.size()){
            if(start[i]!='_')return false;
            i++;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool solve(string &s, string &target, int i) {
//         if (s == target) return true; // Base case for success
//         if (i >= s.size()) return false; // Base case for failure

//         char c = s[i];

//         // Check for 'L' moving left
//         if (c == 'L' && i > 0 && s[i - 1] == '_') {
//             swap(s[i], s[i - 1]);
//             if (solve(s, target, 0)) return true; // Recursive call and return result if true
//             swap(s[i], s[i - 1]); // Backtrack
//         }

//         // Check for 'R' moving right
//         if (c == 'R' && i < s.size() - 1 && s[i + 1] == '_') {
//             swap(s[i], s[i + 1]);
//             if (solve(s, target, 0)) return true; // Recursive call and return result if true
//             swap(s[i], s[i + 1]); // Backtrack
//         }

//         // Explore the next index
//         return solve(s, target, i + 1);
//     }

//     bool canChange(string start, string target) {
//         return solve(start, target, 0);
//     }
// };
