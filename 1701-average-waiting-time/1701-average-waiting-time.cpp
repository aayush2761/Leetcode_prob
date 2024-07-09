class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg=0.0;
        double res=0.0;
        int time =1;
        int i=0;
        while(i<customers.size()){
            // 
            if(time>=customers[i][0]){
                time+=customers[i][1];
                avg+= time-customers[i][0];
                i++;
               

            }
            else time++;

             //cout<<time<<endl;
            
        }
        return avg/(customers.size()*1.0);
    }
};