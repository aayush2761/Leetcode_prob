class Solution {
public:
    int maxDiff(int num) {
        // first operation 
        string t1 = to_string(num);
        char c;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!='9'){
                c=t1[i];
                break;
            }
        }
        // second op 
        char c1=0;
        bool start=false;
        for(int i=0;i<t1.size();i++){
            if(i==0 && t1[i]!='1'){
                c1=t1[i];
                start=true;
                break;
            }
            if( i != 0 && t1[i] != '0' && t1[i] != t1[0]){
                c1=t1[i];
                break;
            }
        }
        // code 
        string num1=t1;
         for(int i=0;i<num1.size();i++){
            if(num1[i]==c){
                num1[i]='9';
            }
        }
        string num2=t1;
        if (c1) {
            for (int i = 0; i < num2.size(); i++) {
                if (start && num2[i] == c1) num2[i] = '1';
                else if (!start && num2[i] == c1) num2[i] = '0';
            }
        }
        return stoi(num1)-stoi(num2);
    }
};