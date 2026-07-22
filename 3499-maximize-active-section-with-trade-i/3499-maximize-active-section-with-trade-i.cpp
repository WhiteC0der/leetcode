class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> temp;
        int ans=0;
        int n =s.length();
        int count =0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') ans++;
        }

        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int count=0;
                while(i<n && s[i]=='0'){
                    count++;
                    i++;
                } 
                temp.push_back(count);
            }else{
                i++;
            }
        }
        int maxone=0;
        for(int i=1;i<temp.size();i++){
            maxone=max(maxone,temp[i]+temp[i-1]);
        }

        return ans+maxone;
    }
};