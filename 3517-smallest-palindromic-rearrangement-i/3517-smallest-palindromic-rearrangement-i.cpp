class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        string ans="";
        char mid;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                mid='a'+i;
            } 
           
            ans+=string(freq[i]/2,'a'+i);
                
        }
        string temp = ans;
        if(mid) ans+=mid;
        
        reverse(temp.begin(),temp.end());

        return ans+temp;
    }
};