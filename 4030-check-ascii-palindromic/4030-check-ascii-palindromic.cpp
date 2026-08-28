class Solution {
public:
    string solve(int num){
        string ans="";
        for(int i=0;i<8;i++){
            if(num%2==1) ans='1' + ans;
            else ans = '0'+ans;
            num/=2;
        }

        return ans;
    }
    bool isPalindromic(string s) {
        int st=0;
        int end=s.length()*8-1;
        string ch="";
        for(int i=0;i<s.length();i++){
            ch+=solve(s[i]);
        }
        while(st<=end){
            if(ch[st]!=ch[end]) return false;
            st++;
            end--;
        }

        return true;
    }
};