class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        int first = to_string(low).size(), last = to_string(high).size();
        vector<int> result;
        string s = "123456789";

        for(int length = first; length <= last; length++){
            for(int start = 0; start <= 9 - length; start++){
                
                string temp = s.substr(start, length);
                int n = stoi(temp);
                if(n >= low && n <= high) 
                    result.push_back(n);
            }
        }

        return result;
    }
};