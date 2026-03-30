class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<int> hash(256,0);
        int minlen=INT_MAX;
        int count=0;
        int sIndex=-1;
        int r=0,l=0;
        
        for(int i=0;i<m;i++) hash[t[i]]++;

        while(r < n){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            while(count == m){
                if( r-l+1 < minlen){
                    minlen=min(minlen,r-l+1);
                    sIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
          
         return minlen == INT_MAX ? "" : s.substr(sIndex, minlen);
    }
};