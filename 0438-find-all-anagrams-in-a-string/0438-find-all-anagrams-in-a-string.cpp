class Solution {
public:
    bool isValid(vector<int> freqs,vector<int> freqp){
        for(int i=0;i<26;i++){
            if(freqs[i]!=freqp[i]) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> freqs(26);
        vector<int> freqp(26);
        vector<int> ans;
        int st=0;
        for(int i=0;i<p.length();i++){
            freqp[p[i]-'a']++;
        }

        for(int end=0;end<s.length();end++){
            freqs[s[end]-'a']++;
            if(end-st+1 > p.length()){
                freqs[s[st++]-'a']--;
            }
            if(isValid(freqs,freqp)) ans.push_back(st);
        }

        return ans;
    }
};