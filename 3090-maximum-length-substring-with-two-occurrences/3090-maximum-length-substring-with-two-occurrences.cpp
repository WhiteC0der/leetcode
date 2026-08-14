class Solution {
public:
    int maximumLengthSubstring(string s) {
        int st=0;
        int end=0;
        int ans=0;
        int freq[26]={0};
        while(end<s.length()){
            freq[s[end]-'a']++;
            while(freq[s[end]-'a']>2){
                freq[s[st]-'a']--;
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }

        return ans;
    }
};