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
        long long lo=1,hi=n;
        while(1){
            long long mid=(lo+hi)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)==1) lo=mid+1;
            else hi=mid-1;
        }
    }
};