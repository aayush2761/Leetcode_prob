/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0;
        int h= n;
        while(l<=h){
            int mid = l + (h-l) /2;
            int x= guess(mid);
            if(x==-1) h=mid-1;
            else if (x==1) l=mid+1;
            else return mid;
        }
        return 0;
    }
};