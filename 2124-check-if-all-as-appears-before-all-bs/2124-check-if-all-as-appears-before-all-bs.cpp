class Solution {
public:
    bool checkString(string s) {
        char temp = 'a';
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' && temp!='a'){
                return false;
            }else if(s[i]=='b'){
                temp = 'b';
            }
        }
        
        return true;
    }
};