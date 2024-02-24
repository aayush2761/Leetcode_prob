class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int e=2*grades.size();
        if(grades.size()==2 || grades.size()==1) return 1;
        if(grades.size()==3){
            if(grades[1]<grades[0]+grades[2]) return 2;
            else{
                return 1;
            }
        }
        int i=3;
        while(i<grades.size()-1){
            int q= i*(i+1);
            if(e/q==0){
               return i-1;
            }
            i++;
        }
        return 0;
    }
};