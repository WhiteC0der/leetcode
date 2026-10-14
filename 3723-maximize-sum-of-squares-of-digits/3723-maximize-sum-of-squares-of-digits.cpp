class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(sum/9,'9');
        if(sum%9 != 0){
            ans+=(sum%9)+'0';
        }
        if(ans.length() > num){
            return "";
        }
        
        ans+=string(num-ans.length(),'0');

        return ans;
    }
};