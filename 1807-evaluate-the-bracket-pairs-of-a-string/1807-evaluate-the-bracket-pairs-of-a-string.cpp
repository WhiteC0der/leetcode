class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        string ans="";
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                i++;
                string key="";
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(mpp.find(key)!=mpp.end()){
                    ans+=mpp[key];
                }else{
                    ans+='?';
                }
            }else{
                ans+=s[i];
            }
        }

        return ans;
    }
};