class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0;
        int j=0;
        int last_pos=-1;
        int last_mac=-1;
        while(i<s.length()){
            if((p[j]==s[i])||p[j]=='?'){
                i++;
                j++;
            }else if(p[j]=='*'){
                last_pos=j;
                last_mac=i;
                j++;
            }else if(last_pos!=-1){//
                last_mac++;
                i=last_mac;
                j=last_pos+1;
            }else{
                return false;
            }
        }
        while(j<p.length()){
            if(p[j]!='*'){
                return false;
            }
            j++;
        }
        return true;
    }
};