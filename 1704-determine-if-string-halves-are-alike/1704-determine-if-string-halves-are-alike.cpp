class Solution {
public:
    bool halvesAreAlike(string s) {
        int mid= s.size()/2;
        char arr[]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l=0, r=0;
        int e=s.size()-1;
        for(int i=0;i<mid;i++){
           for(int j=0;j<10;j++){
               if(s[i]==arr[j]){
                   l++;
               }
                if(s[e-i]==arr[j]){
                   r++;
               }
           }
        }
        if(l==r) return true;
        return false;
    }
};