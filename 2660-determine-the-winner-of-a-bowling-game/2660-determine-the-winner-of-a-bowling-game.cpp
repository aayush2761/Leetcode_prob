// class Solution {
// public:
//     int isWinner(vector<int>& player1, vector<int>& player2) {
//         int res1=0;
//         for(int i=0;i<player1.size();i++){
//             if(i==0) res1+= player1[i];
//             else if(i==1){
//                 if(player1[i-1]>9){
//                     res1+= 2*player1[i];
//                 }
//             }
//             else{
//                 if(player1[i-1]>9 || player1[i-2]>9){
//                     res1+= 2*player1[i];
//                 }
//             }
//         }
//         int res2=0;
//         for(int i=0;i<player2.size();i++){
//             if(i==0) res2+= player2[i];
//             else if(i==1){
//                 if(player2[i-1]>9){
//                     res2+= 2*player2[i];
//                 }
//             }
//             else{
//                 if(player2[i-1]>9 || player2[i-2]>9){
//                     res2+= 2*player2[i];
//                 }
//             }
//         }
//         if(res1>res2) return 1;
//         if(res1<res2) return 2;
//         if(res1==res2) return 0;
//         return -1;

//     }
// };




class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int res1 = 0, res2 = 0;

        // Calculate the score for player 1
        for (int i = 0; i < player1.size(); i++) {
            if (i == 0) {
                res1 += player1[i];
            } else if (i == 1) {
                res1 += (player1[i-1] > 9) ? 2 * player1[i] : player1[i];
            } else {
                res1 += (player1[i-1] > 9 || player1[i-2] > 9) ? 2 * player1[i] : player1[i];
            }
        }

        // Calculate the score for player 2
        for (int i = 0; i < player2.size(); i++) {
            if (i == 0) {
                res2 += player2[i];
            } else if (i == 1) {
                res2 += (player2[i-1] > 9) ? 2 * player2[i] : player2[i];
            } else {
                res2 += (player2[i-1] > 9 || player2[i-2] > 9) ? 2 * player2[i] : player2[i];
            }
        }

        // Determine the winner
        if (res1 > res2) return 1;
        if (res1 < res2) return 2;
        return 0;
    }
};
