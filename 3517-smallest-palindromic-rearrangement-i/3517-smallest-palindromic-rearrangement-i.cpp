class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        string ans="";
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>=2){
                ans+=string(freq[i]/2,'a'+i);
                freq[i]%=2;
            }
        }
        string temp = ans;
        for(int i=0;i<26;i++){
            if(freq[i]>0) ans+=string(freq[i],'a'+i);
        }

        reverse(temp.begin(),temp.end());
        return ans+temp;
    }
};