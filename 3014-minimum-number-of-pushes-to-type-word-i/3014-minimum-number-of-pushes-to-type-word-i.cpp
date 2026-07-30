class Solution {
public:
    int minimumPushes(string s) {
        vector<int> freq(26,0);
        int count=1;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']!=0){
                ans+=freq[s[i]-'a'];
            }else{
                if(count>=1 && count<=8){
                    freq[s[i]-'a']=1;
                }else if(count>=9 && count<=16){
                    freq[s[i]-'a']=2;
                }else if(count<=24){
                    freq[s[i]-'a']=3;
                }else{
                    freq[s[i]-'a']=4;
                }
                count++;
                ans+=freq[s[i]-'a'];
            }
        }

        return ans;
    }
};