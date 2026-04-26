class Solution {
public:
    bool validDigit(int n, int x) {
        string num = to_string(n);
        if(num[0]-'0'==x){
            return false;
        }

        for(int i=1;i<num.length();i++){
            if(num[i]-'0'==x) return true;
        }

        return false;
    }
};