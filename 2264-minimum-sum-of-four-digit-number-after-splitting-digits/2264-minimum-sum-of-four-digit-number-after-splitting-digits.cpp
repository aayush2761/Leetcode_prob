class Solution {
public:
    int minimumSum(int num) {
        
        // sort and add first and last and mid ones
        vector<int> v1;
        
        while(num>0){
            int remainder = num%10;
            v1.push_back(remainder);
            num/=10;
        }
       
        sort(v1.begin(),v1.end());
        int new1=(v1.at(0))*10+v1.at(3);
        int new2=(v1.at(1))*10+v1.at(2);
        return new1+new2;


    }
};