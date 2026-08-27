class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        string temp = s;
        sort(temp.begin(),temp.end(),greater<int>()); // O(nlogn)
        if(t >= temp) return "";
        int freq[26]={0};
        string ans="";
        for(int i=0;i<s.length();i++){ // O(n)
            freq[s[i]-'a']++;
        }
        int j;
        for(j=0;j<t.length();j++){ // O(n)
            if(freq[t[j]-'a']>=1){
                ans+=t[j];
                freq[t[j]-'a']--;
            }else{
                break;
            }
        }

        bool ch=false;
        if(j<t.length()){ // O(n)
        for(int idx=t[j]-'a' ;idx<26;idx++){
            if(freq[idx]>=1){
                ans+=idx+'a';
                freq[idx]--;
                ch=true;
                break;
            }
        }
        }

        while(!ch && !ans.empty()){ // O(n)
            int idx = ans.back()-'a';
            ans.pop_back();
            freq[idx]++;
            for(int i=idx+1;i<26;i++){
                if(freq[i]>=1){
                    ans+=i+'a';
                    freq[i]--;
                    ch=true;
                    break;
                }
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i]>=1){
                ans+=string(freq[i],i+'a');
            }
        }

        return ans;
    }
};