class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        int zero=0;
        int one=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') zero++;
            else one++;
            if(abs(zero-one)<=1) ans++;
        }

        return ans;
    }
};