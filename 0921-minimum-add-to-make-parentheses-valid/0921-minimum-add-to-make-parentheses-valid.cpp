class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }else{
                if(cnt==0) temp++;
                else{
                    cnt--;
                }
            }
        }

        return cnt+temp;
    }
};