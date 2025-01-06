class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>vp;
        // index of one 
        int n = boxes.size();
        for(int i=0;i<n;i++){
            if(boxes[i]=='1')vp.push_back(i);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<vp.size();j++){
                temp+=abs(i-vp[j]);
            }
            res[i]=temp;
        }
        return res;
    }
};