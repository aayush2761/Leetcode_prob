class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // score->+1 loose token[i] have atleat power i 
        // score->-1 gian  token[i]

        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if ( power<tokens[i] ){
                if(score<1 || i==j) return score;
                else{
                    score-=1;
                     power+=tokens[j];
                     j--;
                }
            }

        }
        return score;
    }
};