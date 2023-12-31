class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) { 
        int count=0;
        int el=0;
        for(int i=0; i<tops.size(); i++){
            if(count==0){
                el=tops[i];
                count++;
            } else if(el==tops[i]){
                count++;
            } else {
                count--;
            }
        }
        
        int countb=0;
        int el1=0;
        for(int i=0; i<bottoms.size(); i++){
            if(countb==0){
                el1=bottoms[i];
                countb++;
            } else if(el1==bottoms[i]){
                countb++;
            } else {
                countb--;
            }
        }
        
        int ct=0, cb=0;
        for(int i=0; i<tops.size(); i++){
            if(tops[i]==el) ct++;
            if(bottoms[i]==el1) cb++;
        }
        
        int ans=0;
        if(ct>cb){
            for(int i=0; i<tops.size(); i++){
                if(el!=tops[i]){
                    if(el!=bottoms[i]) return -1;
                    ans++;
                }
            }
        } else {
            for(int i=0; i<tops.size(); i++){
                if(el1!=bottoms[i]){
                    if(el1!=tops[i]) return -1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
