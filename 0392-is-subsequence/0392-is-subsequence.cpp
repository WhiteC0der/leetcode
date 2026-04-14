class Solution {
public:
    bool isSubsequence(string s, string t) {
        int strack=0;
        int ttrack=0;
        while(strack<s.length()&&ttrack<t.length()){
            if(s[strack]==t[ttrack]){
                strack++;
                ttrack++;
            }else{
                ttrack++;
            }
        }
        return strack==s.length();

    }
};